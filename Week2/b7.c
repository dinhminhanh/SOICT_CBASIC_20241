#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
  if(argc != 3) {
    printf("Usage: ./filename <source file> <offset> <target file>\n");
    return 1;
  }

  FILE *f1 = fopen(argv[1], "r");
  FILE *f2 = fopen(argv[3], "w");
  int offset = atoi(argv[2]);
  char line[1024] = { 0 };

  while (fgets(line, sizeof(line) - 1, f1) != NULL) {
    for(int i = 0; i < strlen(line); i ++) {
      line[i] += offset;      
    }
    fputs(line, f2);
    memset(line, sizeof(line), 0);
  }

  fclose(f1);
  fclose(f2);
  printf("File processed successfully.\n");
  return 0;
}