# Bio-snippets
A place for various tiny code-snippets, stuff for discussion, etc.

- [circles](./circles.ipynb) -- an exercise with `tidyr` reshape and `ggplot`-circles with `geom_arc`
- [dotplot-gen](https://github.com/alex-bochkarev/dotplot-gen) -- a dotplots-related tool (see the link for more info, it is a separate repo)
- **Bash tools** aka **Black magic in GNU/Linux**
  - [every-file](./run_for_every_file.sh) -- a boilerplate shellscript to run a command for every file in the current directory (or in some directory; or some type of files in some directory, etc.);
  - [every-file-parallel](./run_for_every_file_parallel.sh) -- same, but in parallel (with GNU [Parallel](https://www.gnu.org/software/parallel/)) (`./parallel_script.sh` is needed just for testing);
  - [example](./example/example.md) -- a quick illustration of `basename` for file processing;
  - [files_from_stdin.py](./files_from_stdin.py) -- passing a list of files from stdin (e.g., from `ls`). Then just do `ls | ./files_from_stdin.py`.
  - [command line join](./join.org) -- joining two csv files with `join` tool from `coreutils` (in GNU/Linux)
- **Folders:**
  - [data](./data/) is where the (demo-) data is stored;
  - [resutls](./results/) is the folder for outputs and results (figures, etc.)
