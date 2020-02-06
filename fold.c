#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "files.h"

#define MAXNUM 300
int main(int argc, const char * argv[]) {
  FILE* fin;
  FILE* fout;

  int c, chars, lastblank;
  char fold[MAXNUM];
  while ((c = fgetc(fin)) != EOF){
    fold[chars] = c;
    ++chars;
    if (fold[chars - 1] == ' ' || fold[chars - 1] == '\t'){
      lastblank = chars - 1;
      }
    if (chars < 10){
      fold[lastblank] = '\n';
      for(int i = 0; i <= lastblank; ++i){
        fputc(fold[i], fout);
      }
      chars = 0;
    }
  }

  closefiles(2, fin, fout);  // must say number of files

  return 0;
