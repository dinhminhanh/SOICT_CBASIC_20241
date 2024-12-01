#include <stdio.h>

enum { SUCCESS, FAIL };
#define MAX_SIZE 100 

int main(void) {
    FILE* fp;
    int p[MAX_SIZE]; 
    int i, n, value, sum = 0;
    int reval = SUCCESS;

    printf("Enter a list of numbers with the first being the size of the list: \n");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        p[i] = value;
        sum += value;  
    }

    if ((fp = fopen("out.txt", "w")) == NULL) {
        printf("Cannot open %s.\n", "out.txt");
        reval = FAIL;
    } else {

        for (i = n - 1; i >= 0; i--) {
            fprintf(fp, "%d ", p[i]);
        }
        fprintf(fp, "%d\n", sum);
        fclose(fp); 
    }

    return reval;
}
