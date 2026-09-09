#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
pid_t pid = fork();
if (pid == 0) {
    printf("[Browser Child] Opening PDF viewer...\n");
    execlp("xdg-open", "xdg-open", "sample.pdf", (char *)NULL);
    exit(0);
} else {
    printf("[Browser Main] Continuing browser execution...\n");
    wait(NULL);
}
return 0;
}
