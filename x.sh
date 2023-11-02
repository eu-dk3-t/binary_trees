#!/bin/bash
ls {0..18}-*.c
echo 'Enter file name: '
read file_n
git add $file_n
echo 'Message: '
read comm
git commit -m $comm
