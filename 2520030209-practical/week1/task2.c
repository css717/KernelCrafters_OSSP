#include <stdio.h>
#include <stdlib.h>

int main() {
printf("=== Task 2: Copy and Move Files ===\n");
system("mkdir -p linux_task2/backup");
system("echo 'Source Data' > linux_task2/source.txt");
system("touch linux_task2/data.txt linux_task2/notes.txt");
system("cp linux_task2/source.txt linux_task2/backup/");
system("cp linux_task2/data.txt linux_task2/backup/data_backup.txt");
system("mv linux_task2/notes.txt linux_task2/backup/");
system("mv linux_task2/source.txt linux_task2/original.txt");
system("ls -R linux_task2");
return 0;
}
