#include <stdio.h>
#include <stdlib.h>

int main() {
printf("=== Task 3: Head and Tail ===\n");
system("mkdir -p linux_task3");
system("printf 'Alice\\nBob\\nCharlie\\nDavid\\nEmma\\nFrank\\nGrace\\nHenry\\nIvy\\nJack\\nKate\\nLiam\\nMia\\nNoah\\nOlivia\\n' > linux_task3/students.txt");
printf("\nFirst 5 Students:\n");
system("head -n 5 linux_task3/students.txt");
printf("\nLast 5 Students:\n");
system("tail -n 5 linux_task3/students.txt");
return 0;
}
