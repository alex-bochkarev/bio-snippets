#!/bin/bash

files=`ls ./*.fasta`  # put files pattern (including the dir) to scan

for file in $files; do
    echo myCoolCommand $file $file.result;
    # change "echo myCoolCommand ..." to whatever you want to run
    # like, "mauve $file $file.result;"
done
