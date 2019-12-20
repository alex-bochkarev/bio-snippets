#!/bin/bash

TSVs=`ls ./tsv/*.tsv`

# process outputs
for file in $TSVs; do
    fname=$(basename $file .tsv)
    if [ ! -e "./fasta/$fname.out.1" ]; then
	      echo "./fasta/$fname.out.1: the first output does not exist"
	      continue
    fi

    if [ ! -e "./fasta/$fname.out.2" ]; then
	      echo "./fasta/$fname.out.2: the first output does not exist"
	      continue
    fi

    echo running mySecondCoolCommand ./fasta/$fname.out.1 ./fasta/$fname.out.2 project=$fname
done
