#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
pid_t pid;
printf("Parent PID: %d, PPID: %d\n", getpid(), getppid());
pid = fork();
if (pid == 0) {
    printf("Child PID: %d, PPID: %d\n", getpid(), getppid());
    sleep(2);
    exit(0);
} else {
    wait(NULL);
    printf("Child finished execution.\n");
}
return 0;
}
