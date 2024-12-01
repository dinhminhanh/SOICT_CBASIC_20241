#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 80
#define MAX_LINE_LENGTH 256

void add_initials_to_file(const char *file_path) {
    FILE *f1 = fopen(file_path, "r");
    if (f1 == NULL) {
        printf("Cannot open file %s\n", file_path);
        return;
    }

    char lines[MAX_LINES][MAX_LINE_LENGTH];
    char firstChars[MAX_LINES + 1];  
    int line_count = 0;

    while (line_count < MAX_LINES && fgets(lines[line_count], sizeof(lines[line_count]), f1)) {
        line_count++;
    }
    fclose(f1);

    for (int i = 0; i < line_count; i++) {
        firstChars[i] = lines[i][0];  
    }
    firstChars[line_count] = '\0';  

    FILE *f2 = fopen(file_path, "a");
    if (f2 == NULL) {
        printf("Cannot open file %s for appending.\n", file_path);
        return;
    }
    fprintf(f2, "\n%s\n", firstChars);
    fclose(f2);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    add_initials_to_file(argv[1]);
    return 0;
}
