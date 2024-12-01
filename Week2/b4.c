#include <stdio.h>
#include <stdlib.h>

void FileAppend(FILE* fin, FILE* fout) {
    int c;
    while ((c = fgetc(fin)) != EOF) {
        fputc(c, fout);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Incorrect number of arguments.\n");
        printf("Usage: append <file1> <file2>\n");
        return 1;
    }
    FILE *f1 = fopen(argv[1], "a");
    if (f1 == NULL) {
        printf("Cannot open '%s' for appending.\n", argv[1]);
        return 1;
    }

    FILE *f2 = fopen(argv[2], "r");
    if (f2 == NULL) {
        printf("Cannot open '%s' for reading.\n", argv[2]);
        fclose(f1);
        return 1;
    }

    FileAppend(f2, f1);

    fclose(f2);
    fclose(f1);

    printf("File '%s' appended to '%s' successfully.\n", argv[2], argv[1]);
    return 0;
}
