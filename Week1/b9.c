#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
    if(argc !=3) {
    printf("Please re-enter");
    return 1;
    }
    double length = atof(argv[1]);cl
    double width = atof(argv[2]);

    double area = length * width;
    double perimeter = 2 * (length + width);
    printf("Area = %.2f\n",area);
    printf("Perimeter = %.2f\n",perimeter);
    return 0;
}