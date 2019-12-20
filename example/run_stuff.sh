#!/bin/bash

TSVs=`ls ./tsv/*.tsv`

# process .tsv files first
for file in $TSVs; do
    fname=$(basename $file .tsv)
    echo running myCoolCommand $file ./fasta/$fname.out.1 ./fasta/$fname.out.2;
    touch fasta/$fname.out.1
    touch fasta/$fname.out.2
done

