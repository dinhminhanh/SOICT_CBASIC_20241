#include <stdio.h>
#include <stdlib.h>

void LineMerge(FILE *f1, FILE *f2, FILE *f3) {
    char line1[100], line2[100];
    while (fgets(line1, sizeof(line1), f1) != NULL) {
        fputs(line1, f3); 
        if (fgets(line2, sizeof(line2), f2) != NULL) {
            fputs(line2, f3);
        }
    }
    while (fgets(line2, sizeof(line2), f2) != NULL) {
        fputs(line2, f3);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: merge <file1> <file2> <file3>\n");
        return 1;
    }

    FILE *f1 = fopen(argv[1], "r");
    if (f1 == NULL) {
        printf("Cannot open file %s\n", argv[1]);
        return 1;
    }

    FILE *f2 = fopen(argv[2], "r");
    if (f2 == NULL) {
        printf("Cannot open file %s\n", argv[2]);
        return 1;
    }

    FILE *f3 = fopen(argv[3], "w");
    if (f3 == NULL)  {
        printf("Cannot open file %s\n", argv[3]);
        return 1;
    }

    LineMerge(f1, f2, f3);
    fclose(f1);
    fclose(f2);
    fclose(f3);
    printf("Files merged successfully into %s\n", argv[3]);
    return 0;
}
