#include <stdio.h>
#include <stdlib.h>

void CharReadWrite(FILE* fin, FILE* fout){
    int c;
    while ((c = fgetc(fin)) != EOF){
        fputc(c, fout);
        putchar(c);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Incorrect number of arguments.\n");
        printf("Usage: Copy <file1> <file2>\n");
        return 1;
    }

    FILE *fprt1 = fopen(argv[1], "r");
    if (fprt1 == NULL) {
        printf("Cannot open '%s'.\n", argv[1]);
        return 1;
    }

    FILE *fprt2 = fopen(argv[2], "w");
    if (fprt2 == NULL) {
        printf("Cannot open '%s'.\n", argv[2]);
        fclose(fprt1);
        return 1;
    }
    CharReadWrite(fprt1, fprt2);
    fclose(fprt1);
    fclose(fprt2);    
    printf("File copied successfully from '%s' to '%s'.\n", argv[1], argv[2]);
    return 0;
}
