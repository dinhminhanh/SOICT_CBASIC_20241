#include <stdio.h>

int main(){
 int A[10];
 printf("please enter 10 numbers:\n");
 for(int i=0; i<10; i++)
 scanf("%d", &A[i]);
 printf("numbers in reversed order:\n");
 for(int i=9; i>=0; i--)
 printf("%d\n", A[i]);
return 0;
}