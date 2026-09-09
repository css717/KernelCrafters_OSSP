#include <stdio.h>
#include <stdlib.h>

int main() {
printf("=== Task 1: File Operations ===\n");
system("mkdir -p linux_task1 && cd linux_task1 && touch file1.txt file2.txt file3.txt file4.txt file5.txt");
system("echo 'Content in file1' > linux_task1/file1.txt");
system("rm -f linux_task1/file5.txt");
system("ls -l linux_task1");
return 0;
}
