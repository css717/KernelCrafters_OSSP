#include <stdio.h>
#include <stdlib.h>

int main() {
printf("=== Task 7: Permission Lab ===\n");
system("mkdir -p permission_lab && echo 'Test Content' > permission_lab/test.txt");
system("chmod -r permission_lab/test.txt");
system("cat permission_lab/test.txt 2>/dev/null || echo 'Read Access Denied (Expected)'");
system("chmod +r permission_lab/test.txt");
return 0;
}
