#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char *argv[]){
    if(argc !=4) {
    printf("Please re-enter");
    return 1;
    }

    double a = atof(argv[1]);
    double b = atof(argv[2]);
    double c = atof(argv[3]);
     if (a == 0) {
        printf("Invalid input a\n");
        return 1;
    }
    double delta = b * b - 4*a*c;
    if(delta < 0) printf("Equation with no solution \n");
    else if (delta == 0){
        double x = -b/(2*a);
        printf("x1 = x2 = %.2f",x);
    }
    else{
        double x1 = (-b + sqrt(delta))/(2*a);
        double x2 = (-b - sqrt(delta))/(2*a);
        printf("x1 = %.2f \n",x1);
        printf("x2 = %.2f \n",x2);
    }
    return 0;
}