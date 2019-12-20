# A quick bash illustration
## General theory
What you'd want is a `basename` command. From `man basename`:
```
SYNOPSIS
       basename NAME [SUFFIX]
       basename OPTION... NAME...

DESCRIPTION
       Print NAME with any leading directory components removed.  If specified, also remove a trailing SUFFIX.
```
That is, `basename $file .ext` will extract a filename from `$file` for you, without a path and without an extension `.ext` (if specified).

## An example
### Initial directory structure
At first, the directory structure is as follows:
```
.
├── fasta
├── process_stuff.sh
├── run_stuff.sh
└── tsv
    ├── file1.tsv
    └── file2.tsv
```

### Generating the stuff
To emulate a python script (or whatever) -- process files in the `tsv` directory and produce two outputs in the `fasta` file for each input file. That is, after we run `./run_stuff.sh`, the output will be:
```
running myCoolCommand ./tsv/file1.tsv ./fasta/file1.out.1 ./fasta/file1.out.2
running myCoolCommand ./tsv/file2.tsv ./fasta/file2.out.1 ./fasta/file2.out.2
```
And the following directory structure (two output files created for each input .tsv):

```
.
├── fasta
│   ├── file1.out.1
│   ├── file1.out.2
│   ├── file2.out.1
│   └── file2.out.2
├── process_stuff.sh
├── run_stuff.sh
└── tsv
    ├── file1.tsv
    └── file2.tsv
```

See the script [source](./run_stuff.sh). I just have used `touch` to create empty files, for demo purposes.

### Processing the stuff
Now assume we want to process each pair of output files from the previous step. After we run `./process_stuff.sh` we'll have:
```
running mySecondCoolCommand ./fasta/file1.out.1 ./fasta/file1.out.2 project=file1
running mySecondCoolCommand ./fasta/file2.out.1 ./fasta/file2.out.2 project=file2
```

if we don't have one of the inputs -- e.g., after `rm ./fasta/file1.out.1`, running the script gives:
```
./fasta/file1.out.1: the first output does not exist
running mySecondCoolCommand ./fasta/file2.out.1 ./fasta/file2.out.2 project=file2
```

See the script [source](./process_stuff.sh)
