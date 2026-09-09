#include <stdio.h>
#include <stdlib.h>

int main() {
system("mkdir -p linux_project/source linux_project/backup linux_project/docs");
system("touch linux_project/source/main.c linux_project/source/helper.c linux_project/source/README.txt");
system("mv linux_project/source/helper.c linux_project/source/functions.c");
system("chmod 644 linux_project/source/README.txt");
printf("Linux Project setup completed.\n");
return 0;
}
