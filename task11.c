#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) {
        // Child process launches the PDF application
        printf("[Browser Child] Opening PDF viewer...\n");
        execlp("xdg-open", "xdg-open", "sample.pdf", (char *)NULL);
        
        // Executes only if execlp fails
        perror("Exec failed");
        exit(1);
    } else {
        // Parent process continues running (Browser UI stays active)
        printf("[Browser Main] Continuing browser execution...\n");
        wait(NULL);
        printf("[Browser Main] PDF Viewer process closed.\n");
    }

    return 0;
}

