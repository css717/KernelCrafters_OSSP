#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void processCommand(char *command) {
if (strcmp(command, "hello") == 0) printf("Hello! Welcome to MyShell.\n");
else if (strcmp(command, "help") == 0) printf("Available: hello, help, exit\n");
else if (strlen(command) > 0) printf("Unknown command: %s\n", command);
}

int main() {
char buffer[100];
while (1) {
    printf("myshell>");
    fflush(stdout);
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) break;
    buffer[strcspn(buffer, "\n")] = '\0';
    if (strcmp(buffer, "exit") == 0) break;
    processCommand(buffer);
}
return 0;
}
