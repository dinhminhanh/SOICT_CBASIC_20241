#include <stdlib.h>
#include<stdio.h>
int main(){
    int i, n, *p;
    printf("How many numbers do you want to enter?\n");
    scanf("%d", &n);
    p = (int *)malloc(n * sizeof(int));
    if (p == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    printf("Pleas enter the numbers\n");
    for(int i =0; i<n;i++) scanf("%d",&p[i]);
    printf("The numbers in reverse\n");
    for(i = n-1; i >= 0; --i) printf("%d\n",p[i]);
    free(p); 
    return 0;
}
