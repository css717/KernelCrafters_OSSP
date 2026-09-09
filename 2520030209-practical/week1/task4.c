#include <stdio.h>
#include <stdlib.h>

int main() {
printf("=== Task 4: Organize Files ===\n");
system("mkdir -p organization/documents organization/images");
system("touch organization/file1.txt organization/file2.txt organization/file3.txt organization/image1.jpg organization/image2.jpg");
system("mv organization/*.txt organization/documents/");
system("mv organization/*.jpg organization/images/");
system("mv organization/documents/file1.txt organization/documents/notes.txt");
system("mv organization/images/image1.jpg organization/images/photo.jpg");
system("ls -R organization");
return 0;
}
