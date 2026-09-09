#!/bin/bash
mkdir -p linux_task2/backup && cd linux_task2
touch source.txt data.txt notes.txt
echo "Source Data" > source.txt
cp source.txt backup/
cp data.txt backup/data_backup.txt
mv notes.txt backup/
mv source.txt original.txt
ls -R
