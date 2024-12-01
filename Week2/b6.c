#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
     if (argc != 3) {
        printf("Incorrect number of arguments.\n");
        return 1;
    }

    FILE *fin = fopen(argv[1], "r");
    if (fin == NULL) {
        printf("Cannot open file %s\n", argv[1]);
        return 1;
    }
    
    FILE *fout = fopen(argv[2], "w");
    if (fout == NULL) {
        printf("Cannot open file %s\n",argv[2]);
        fclose(fin);
        return 1;
    }

    char line[1024];
    while (fgets(line, sizeof(line), fin) != NULL) {
        fputs(line, fout);
        fputs("\n", fout); 
    }

    fclose(fin);
    fclose(fout);
    return 0;
}