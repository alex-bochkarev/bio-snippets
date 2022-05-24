/* Based on StackOverflow answer:
 * https://unix.stackexchange.com/questions/18736/how-to-count-the-number-of-a-specific-character-in-each-line
 *
 * Counts number of 'NA' substrings in each line,
 * and prints only lines when this number is below
 * constant MAX_NO_NA.
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_NO_NA 3

int main(int argc, char *argv[])
{
  char * line = NULL;
  size_t len = 0;
  int no_lines = 0, lines_printed = 0;

  while (getline(&line, &len, stdin) != -1)
    {
      int count = 0; // NANs count per line

      /* Modes:
         1 -- just seen N,
         2 -- just seen NA,
         0 -- reset. */
      int mode = 0;

      char * s = line;
      while (*s) {
        if((*s == 'N') && mode ==0 )mode++;
        if((*s == 'A') && mode ==1 )mode++;
        if((*s == 'N') && mode ==2 ){
          count++;
          mode = 0;
        }
        s++;
      }
      if (count <= MAX_NO_NA){
        printf("%s", line);
        lines_printed++;
      };
      no_lines++;
    }
  fprintf(stderr, "%d lines printed out of %d in total.\n", lines_printed, no_lines);
  if(line) free(line);
  return 0;
}
