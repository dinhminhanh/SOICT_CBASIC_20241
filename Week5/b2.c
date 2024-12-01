#include<stdio.h>

void Convert(int N) {
    if (N == 0) return;
    Convert(N / 2); 
    int b = N % 2;  
    printf("%d", b); 
}

int main(){
    int N;
    scanf("%d", &N);  
    if (N == 0) {
        printf("0"); 
    } else {
        Convert(N); 
    }
    return 0;
}
