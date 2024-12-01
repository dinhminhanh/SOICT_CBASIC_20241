#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 20
#define MAX_TEL 11
#define MAX_EMAIL 25

typedef struct {
    char name[MAX_NAME];
    char tel[MAX_TEL];
    char email[MAX_EMAIL];
} PhoneAddress;

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <source_file> <N> <output_file1> <output_file2>\n", argv[0]);
        return 1;
    }
    
    char *source_file = argv[1];  
    int N = atoi(argv[2]);
    char *file1 = argv[3];
    char *file2 = argv[4];

    FILE *src_file = fopen(source_file, "rb"); 
    if (src_file == NULL) {
        perror("Cannot open source file");
        return 1;
    }

    FILE *out1 = fopen(file1, "wb");
    FILE *out2 = fopen(file2, "wb");
    if (out1 == NULL || out2 == NULL) {
        perror("Cannot open output files");
        fclose(src_file);
        return 1;
    }

    PhoneAddress phone;
    int count = 0;

    while (fread(&phone, sizeof(PhoneAddress), 1, src_file) == 1) {
        if (count < N) {
            fwrite(&phone, sizeof(PhoneAddress), 1, out1);
        } else {
            fwrite(&phone, sizeof(PhoneAddress), 1, out2);
        }
        count++;
    }

    fclose(src_file);
    fclose(out1);
    fclose(out2);

    printf("Split complete.\n");
    return 0;
}
