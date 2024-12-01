#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show_full_content(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Cannot open file '%s'\n", filename);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
}

void show_by_page(const char *filename, int lines_per_page) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Cannot open file '%s'\n", filename);
        return;
    }

    char line[256];
    int line_count = 0;

    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
        line_count++;

        if (line_count == lines_per_page) {
            printf("\n-- Press any key to continue --\n");
            getchar(); 
            line_count = 0;  
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: <filename> [-p]\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    int page_mode = (argc == 3 && strcmp(argv[2], "-p") == 0);

    if (page_mode) {
        show_by_page(filename, 5);  
    } else {
        show_full_content(filename);  
    }

    return 0;
}
