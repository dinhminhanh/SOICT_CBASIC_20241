#include <stdio.h>

int count = 0; 

int c(int k, int n) {
    count++; 
    if (k == 0 || k == n) return 1; 
    return c(k, n - 1) + c(k - 1, n - 1);
}

int main() {
    int k, n;
    scanf("%d %d", &k, &n);
    
    printf("C(%d,%d) = %d\n", k, n, c(k,n)); 
    printf("Count: %d\n", count); 
    return 0;
}
