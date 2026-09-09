#include <stdio.h>
#include <string.h>

int main() {
char cmd[100];
while (1) {
    printf("myshell> ");
    if (!fgets(cmd, sizeof(cmd), stdin)) break;
    cmd[strcspn(cmd, "\n")] = 0;
    if (strcmp(cmd, "exit") == 0) break;
    printf("You typed: %s\n", cmd);
}
return 0;
}
