#include <stdio.h>
#include <stdlib.h>

#define SIZE 1024 

int main(int argc, char *argv[]) {
    FILE *File1, *File2;
    char buffer[SIZE];
    size_t bytesRead;
    if(argc<3) {
    printf("%s <file1> <file2>\n",argv[0]);
    exit(1);
}

    File1 = fopen(argv[1], "r"); 
    if (File1 == NULL) {
        perror("Cannot open source file");
        return 1;
    }

    File2 = fopen(argv[2], "w");
    if (File2 == NULL) {
        perror("Cannot open destination file");
        fclose(File1);
        return 1;
    }

    while ((bytesRead = fread(buffer, 1, SIZE, File1)) > 0) {
        fwrite(buffer, 1, bytesRead, File2);
    }
    fclose(File1);
    fclose(File2);

    printf("File copied successfully from %s to %s\n", argv[1], argv[2]);
    return 0;
}
