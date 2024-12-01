#include <stdio.h>

int n, k;
int x[100];

void print() {
    for(int i = 1; i <= k; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
}

void Try(int i) {
    for(int v = x[i-1] + 1; v <= n-k+i; v++) {
        x[i] = v;
        if(i == k) { 
            print();
        } else {
            Try(i+1);
        }
    }
}

int main() {
    scanf("%d %d", &n, &k);
    x[0] = 0; 
    Try(1);
    return 0;
}