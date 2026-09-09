#!/bin/bash
mkdir -p linux_task1 && cd linux_task1
touch file1.txt file2.txt file3.txt file4.txt file5.txt
ls -l
echo "Hello Task 1" > file1.txt
cat file1.txt
rm file5.txt
ls -l
