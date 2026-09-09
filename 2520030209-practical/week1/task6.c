#include <stdio.h>
#include <stdlib.h>

int main() {
printf("=== Task 6: Permissions ===\n");
system("mkdir -p linux_task4");
system("echo 'public' > linux_task4/public.txt");
system("echo 'private' > linux_task4/private.txt");
system("chmod 600 linux_task4/private.txt");
system("chmod 644 linux_task4/public.txt");
system("ls -l linux_task4");
return 0;
}
