#include <stdio.h>
#include <stdlib.h>

int main() {
printf("=== Task 8: Backup and Restore ===\n");
system("mkdir -p linux_task6/backup");
system("printf 'L1\\nL2\\nL3\\nL4\\nL5\\nL6\\nL7\\nL8\\nL9\\nL10\\n' > linux_task6/important.txt");
system("cp linux_task6/important.txt linux_task6/backup/important_backup.txt");
system("rm linux_task6/important.txt");
system("cp linux_task6/backup/important_backup.txt linux_task6/important_restored.txt");
system("cat linux_task6/important_restored.txt");
return 0;
}
