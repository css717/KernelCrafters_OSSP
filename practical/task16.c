#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

#define FIFO_C2S "client_to_server"
#define FIFO_S2C "server_to_client"

void handle_sigchld(int sig) {
    (void)sig;
    while (waitpid(-1, NULL, WNOHANG) > 0);
}

void handle_sigint(int sig) {
    (void)sig;
    unlink(FIFO_C2S);
    unlink(FIFO_S2C);
    printf("\nServer shutdown complete.\n");
    exit(0);
}

int main() {
    char buffer[256];

    signal(SIGCHLD, handle_sigchld);
    signal(SIGINT, handle_sigint);

    mkfifo(FIFO_C2S, 0666);
    mkfifo(FIFO_S2C, 0666);

    printf("Server listening on FIFOs...\n");

    while (1) {
        int fd_read = open(FIFO_C2S, O_RDONLY);
        if (fd_read < 0) continue;

        memset(buffer, 0, sizeof(buffer));
        if (read(fd_read, buffer, sizeof(buffer)) > 0) {
            printf("[Server Received]: %s\n", buffer);

            pid_t pid = fork();
            if (pid == 0) {
                int fd_write = open(FIFO_S2C, O_WRONLY);
                char response[300];
                snprintf(response, sizeof(response), "Server Processed: %s", buffer);
                write(fd_write, response, strlen(response) + 1);
                close(fd_write);
                exit(0);
            }
        }
        close(fd_read);
    }

    return 0;
}
