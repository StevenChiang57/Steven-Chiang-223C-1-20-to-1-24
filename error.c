#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "files.h"

#define MAXNUM 300
#define MAX_TEXT_PER_LINE 10
int main(int argc, const char * argv[]) {
  FILE* fin;
  FILE* fout;

  if (!open_io_files(argc, argv, &fin, &fout, 3, 4,                   "Usage: ./detab inputfile outputfile tab_interval (optional)\n")) {
    exit(1);
  }
  int c, paren, brack, brace, squote, dquote, escape, comment;
  while ((c = fgetc(fin)) != EOF){
    if (c == '{' || c =='}')
      ++brace;
    else if (c == '(' || c == ')')
      ++paren;
    else if (c == '[' || c == ']')
      ++brack;
    else if (c == '\'')
      ++squote;
    else if (c == '"')
      ++dquote;
  }
  if ((paren % 2) == 1)
    fprintf(stderr, "Error: unmatched parentheses\n");
  if ((brack % 2) == 1)
    fprintf(stderr, "Error: unmatched brackets\n");
  if ((brace % 2) == 1)
    fprintf(stderr, "Error: unmatched braces\n");
  if ((squote % 2) == 1)
    fprintf(stderr, "Error: unmatched single quotes\n");
  if ((dquote % 2) == 1)
    fprintf(stderr, "Error: unmatched double quotes\n");
  closefiles(2, fin, fout);  // must say number of files

  return 0;
}
