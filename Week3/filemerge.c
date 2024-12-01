#include <stdio.h>
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
    if (argc != 4) {
        printf("Usage: %s <input_file1> <input_file2> <output_file>\n", argv[0]);
        return 1;
    }

    char *file1 = argv[1];
    char *file2 = argv[2];
    char *file = argv[3];

    FILE *in1 = fopen(file1, "rb");
    FILE *in2 = fopen(file2, "rb");
    FILE *out = fopen(file, "wb");

    if (in1 == NULL || in2 == NULL || out == NULL) {
        perror("Error opening files");
        return 1;
    }

    PhoneAddress phone;
    int count = 0;

    while (fread(&phone, sizeof(PhoneAddress), 1, in1) == 1) {
        fwrite(&phone, sizeof(PhoneAddress), 1, out);
        count++;
    }

    while (fread(&phone, sizeof(PhoneAddress), 1, in2) == 1) {
        fwrite(&phone, sizeof(PhoneAddress), 1, out);
        count++;
    }

    fclose(in1);
    fclose(in2);
    fclose(out);

    printf("Merge complete\n");
    return 0;
}