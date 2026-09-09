#!/bin/bash
mkdir -p organization/documents organization/images && cd organization
touch file1.txt file2.txt file3.txt image1.jpg image2.jpg
mv *.txt documents/
mv *.jpg images/
mv documents/file1.txt documents/notes.txt
mv images/image1.jpg images/photo.jpg
ls -l documents/ images/
