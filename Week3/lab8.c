#include <stdio.h>
#include <stdlib.h>

#define SIZE 1024

int main() {
    FILE *file1, *file2;
    char buffer[SIZE];
    size_t bytes_read;
    file1 = fopen("lab1.txt", "r");
    if (file1 == NULL) {
        perror("Can not open file\n");
        return 1;
    }
    file2 = fopen("lab1a.txt", "w");
    if (file2 == NULL) {
        perror("Can not open file\n");
        fclose(file1);
        return 1;
    }

    while (!feof(file1)) {
        bytes_read = fread(buffer, 1, SIZE, file1);
        if (bytes_read > 0) {
            fwrite(buffer, 1, bytes_read, file2);
        }
    }

    fclose(file1);
    fclose(file2);
    printf("File copy complete.\n");
    return 0;
}