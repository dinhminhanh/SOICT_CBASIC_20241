#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

void LineReadWrite(FILE *fin, FILE *fout) {
    char buff[MAX_LEN];
    int len = 0;
    while (fgets(buff, MAX_LEN, fin) != NULL) {
        len = strlen(buff);
        fprintf(fout, "%d %s\n", len, buff);
        printf("%d %s\n", len, buff);
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: ./filename <source file> <target file>\n");
        return 1;
    }

    FILE *fin = fopen(argv[1], "r");
    if (fin == NULL) {
        printf("Cannot open source file %s\n", argv[1]);
        return 1;
    }

    FILE *fout = fopen(argv[2], "w");
    if (fout == NULL) {
        printf("Cannot open target file %s\n", argv[2]);
        fclose(fin);
        return 1;
    }

    LineReadWrite(fin, fout);
    fclose(fin);
    fclose(fout);
    return 0;
}
