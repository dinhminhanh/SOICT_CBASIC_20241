#include <stdio.h>
#include <stdlib.h>

#define SIZE 1024

int main(int argc, char *argv[]) {
    FILE *file;
    char buffer[SIZE];
    size_t bytes_read;

    if (argc != 2) {
        fprintf(stderr, "Use: %s <file_name>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Can not open");
        return 1;
    }
    while ((bytes_read = fread(buffer, 1, SIZE, file)) > 0) {
        fwrite(buffer, 1, bytes_read, stdout);
    }
    fclose(file);
    return 0;
}