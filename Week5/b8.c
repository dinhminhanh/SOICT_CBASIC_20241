#include<stdio.h>
#include<math.h>

int PerfectSquares(int a){
   int b = (int)sqrt(a);
   return (b *b == a);
}

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    int count =0;
    for(int i=0; i<n; i++){
       if(PerfectSquares(a[i])) count ++;
    }

    printf("%d", count);
    return 0;
}