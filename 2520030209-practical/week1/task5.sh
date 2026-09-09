#!/bin/bash
mkdir -p project/{source/{c,python},docs,backup} && cd project
touch source/c/f1.c source/c/f2.c source/c/f3.c
touch source/python/f1.py source/python/f2.py
tree . || ls -R
rmdir backup
