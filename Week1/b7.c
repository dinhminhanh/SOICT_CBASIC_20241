#include<stdio.h>
#include<math.h>

void split(double num, int *int_part,double *frac_part){
    *int_part = (int)num;
    *frac_part = num - *int_part;
}
int main(){
    double num;
    int int_part;
    double frac_part;

    scanf("%lf",&num);
    split(num, &int_part, &frac_part);
    printf("%d %.4f", int_part, frac_part);
    return 0;

}