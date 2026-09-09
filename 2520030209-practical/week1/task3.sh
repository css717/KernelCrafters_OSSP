#!/bin/bash
mkdir -p linux_task3 && cd linux_task3
printf "Alice\nBob\nCharlie\nDavid\nEmma\nFrank\nGrace\nHenry\nIvy\nJack\nKate\nLiam\nMia\nNoah\nOlivia\n" > students.txt
cat students.txt
head -n 5 students.txt
head -n 10 students.txt
tail -n 5 students.txt
tail -n 10 students.txt
