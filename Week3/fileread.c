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
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    char *file = argv[1];
    FILE *fp = fopen(file, "rb");

    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    PhoneAddress phone;
    int count = 0;

    printf("%-20s %-11s %-25s\n", "Name", "Telephone", "Email");

    while (fread(&phone, sizeof(PhoneAddress), 1, fp) == 1) {
        printf("%-20s %-11s %-25s\n", phone.name, phone.tel, phone.email);
        count++;
    }

    fclose(fp);
    return 0;
}