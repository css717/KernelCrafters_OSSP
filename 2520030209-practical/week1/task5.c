#include <stdio.h>
#include <stdlib.h>

int main() {
printf("=== Task 5: Directory Management ===\n");
system("mkdir -p project/source/c project/source/python project/docs project/backup");
system("touch project/source/c/1.c project/source/c/2.c project/source/c/3.c");
system("touch project/source/python/1.py project/source/python/2.py");
system("rmdir project/backup");
system("ls -R project");
return 0;
}
