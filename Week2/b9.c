#include <stdio.h>
#define MAX_LEN 20

enum { SUCCESS, FAIL };

int LineReadWrite(FILE* fin) {
    char buff[MAX_LEN]; 
    int count = 0;
    while (fgets(buff, MAX_LEN, fin) != NULL) {
        count++; 
        printf("%s", buff);
    }
    return count;
}

int main() {
    FILE* fptr1;
    int c = 0;
    char filename1[] = "haiku.txt"; 
    int reval = SUCCESS;

    if ((fptr1 = fopen(filename1, "r")) == NULL) {
        printf("Cannot open %s.\n", filename1);
        reval = FAIL;
    } else {
        printf("Reading file %s ... done!\n", filename1); // Sửa lại ở đây
        c = LineReadWrite(fptr1); 
        printf("This file has %d lines\n", c); // Thay đổi ở đây
        fclose(fptr1); 
    }

    return reval;
}
