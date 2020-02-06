#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "files.h"

#define MAXNUM 300
#define IN 1
#define OUT 0
int main(int argc, const char * argv[]) {
  FILE* fin;
  FILE* fout;

  if (!open_io_files(argc, argv, &fin, &fout, 3, 4,                   "Usage: ./detab inputfile outputfile tab_interval (optional)\n")) {
    exit(1);
  }
  /* */
  int c, incomment, inquotes, lastchar = fgetc(fin);
  char noncomment[MAXNUM];
  while ((c = fgetc(fin)) != EOF){
    if (lastchar == '"'){
      while (c != '"'){
        fputc(lastchar, fout);
        lastchar = c;
        c = fgetc(fin);
      }
    }
    if (lastchar == '/' &&  c == '*'){
      while (lastchar != '*' && c != '/'){
        lastchar = c;
        c = fgetc(fin);
        }
      }
    if (lastchar == '/' &&  c == '/'){
      while (c != '\n'){
        lastchar = c;
        c = fgetc(fin);
        }
    fputc(lastchar , fout);
    lastchar = c;
}
}
  closefiles(2, fin, fout);  // must say number of files

  return 0;
}
