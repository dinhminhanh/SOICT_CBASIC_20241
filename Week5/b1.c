#include<stdio.h>

int Try(int a, int b){
    if (a == b) return a;
    else if (a > b) return Try(a-b, b);
    else return Try(a, b-a);
}

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", Try(a, b));
    return 0;
}