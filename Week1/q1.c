#include<stdio.h>
#include<math.h>

int main(){
    int i ,n;
    int A[100];
    int count =0;
    scanf("%d", &n);
    for (i = 0 ; i <n; i++){
        scanf("%d", &A[i]);
    }
for (i = 0 ; i <n; i++){
    double sqrt_num = (double)sqrt(A[i]);
     int sqrt_int = (int)sqrt_num;
     if (sqrt_num == sqrt_int) {
            count ++;
        

}
}
printf("%d \n", count);
return 0;
}