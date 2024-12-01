#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void convertToUpper(FILE *file) {
    int c;
    long pos; 
    while ((c = fgetc(file)) != EOF) {
        if (islower(c)) {
            c = toupper(c); 
        }

        pos = ftell(file); //get current cursor position
        fseek(file, pos - 1, SEEK_SET);
        fputc(c, file);
        fseek(file, pos, SEEK_SET); //move pointer to the next position
    }
}
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Incorrect number of arguments.\n");
        return 1;
    }
    FILE *file = fopen(argv[1], "r+"); 
    if (file == NULL) {
        printf("Cannot open %s.\n", argv[1]);
        return 1;
    }

    convertToUpper(file);
    fclose(file);
    printf("File '%s' has been successfully converted to uppercase.\n", argv[1]);

    return 0;
}
