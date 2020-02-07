#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "files.h"

#define MAXNNUM 500
#define IN 1
#define OUT 0
int main(int argc, const char * argv[]) {
  FILE* fin;
  FILE* fout;

  if (!open_io_files(argc, argv, &fin, &fout, 3, 4,                   "Usage: ./detab inputfile outputfile tab_interval (optional)\n")) {
    exit(1);
  }

  int lastchar, c , nextchar;
  while ((c = fgetc(fin)) != EOF) {
    if (c == '"'){
      lastchar = c;
      fputc(c , fout);
      c = fgetc(fin);
      while (c != '"'){
        lastchar = c;
        fputc(lastchar, fout);
        c = fgetc(fin);
      }
      lastchar = c;
      fputc(lastchar, fout);
    }
    else if (c == '/'){
      nextchar = fgetc(fin);
      if(nextchar == '*'){  // /* comment */ case
        while (lastchar != '*' || c != '/'){
          lastchar = c;
          c = fgetc(fin);
        }
      }
      else if (nextchar == '/'){ // double slash comment case
        while (c != '\n'){
          lastchar = c;
          c = fgetc(fin);
        }
        fputc('\n', fout);
      }
      else {
        fputc(c, fout);
      }
    }
    else{
      lastchar = c;
      fputc(lastchar, fout);
    }


  }




  closefiles(2, fin, fout);  // must say number of files

  return 0;
}
