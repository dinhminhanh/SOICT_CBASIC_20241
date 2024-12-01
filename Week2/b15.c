#include <stdio.h>
#include <stdlib.h>

enum { SUCCESS, FAIL, MAX_ELEMENT = 10 };

typedef struct {
    int no;
    char name[20];
    double price;
} product;

int main() {
    FILE* fp;
    product arr[MAX_ELEMENT];
    int i = 0;
    int reval = SUCCESS; 

    if ((fp = fopen("product.txt", "r")) == NULL) {
        printf("Cannot open product.txt.\n"); 
        reval = FAIL;
        return reval; 
    }

    while (i < MAX_ELEMENT && fscanf(fp, "%d %s %lf", &arr[i].no, arr[i].name, &arr[i].price) == 3) {
        i++;
    }
    fclose(fp);

    printf("No\tProduct Name\t\tPrice\n");
    for (int j = 0; j < i; j++) {
        printf("%d\t%s\t\t%.1lf\n", arr[j].no, arr[j].name, arr[j].price); 
    }
    return reval;
}
