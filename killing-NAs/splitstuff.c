/* Based on `man 3 getline`.
 * Counts number of substrings like '\t<nothing><\t or EOL> 'in each line, and
 * prints only lines when this number is below constant MAX_NO_NA.
 * Example:
 *   $ ./a.out ./example.csv
 * will count NAs in the file.
*/
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
  FILE * infile, *gofile, *bofile;
  char *line = NULL;
  size_t len = 0;
  ssize_t nread;

  infile = fopen(argv[1], "r");
  if (infile == NULL) {
    perror("fopen");
    exit(EXIT_FAILURE);
  }

  while ((nread = getline(&line, &len, infile)) != -1) {
    bool newfield=false;
    int NA_count = 0;

    for(int i=0;line[i]!=0; i++){
      if (line[i]=='\t'){
        if(newfield){
          NA_count++;
        }else{
          newfield=true;
        }
      } else newfield=false;
    }
    printf("This has %d NAs:\n --> %s", NA_count, line);
  }

  free(line);
  fclose(infile);
  exit(EXIT_SUCCESS);
}
