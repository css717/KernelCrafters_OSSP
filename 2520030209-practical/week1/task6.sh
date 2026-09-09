#!/bin/bash
mkdir -p linux_task4 && cd linux_task4
echo "Public" > public.txt
echo "Private" > private.txt
echo "echo Executing" > script.sh
chmod 600 private.txt
chmod 644 public.txt
chmod +x script.sh
ls -l
chmod -x script.sh
ls -l
