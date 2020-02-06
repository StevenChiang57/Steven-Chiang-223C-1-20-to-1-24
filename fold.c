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

  int c, chars, lastblank;
  char fold[MAXNUM];
  chars = lastblank = 0;
  while ((c = fgetc(fin)) != EOF){
    fold[chars] = c;
    if (fold[chars] == ' ' || fold[chars] == '\t'){
      lastblank = chars;
      }
    ++chars;
    if (chars > MAX_TEXT_PER_LINE){
      fold[lastblank] = '\n';
      for(int i = 0; i < MAX_TEXT_PER_LINE + 1; ++i){
        fputc(fold[i], fout);
      }
      chars = 0;
    }

  }

  closefiles(2, fin, fout);  // must say number of files

  return 0;
}
