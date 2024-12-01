#include <stdio.h>
#include <math.h>
#define MAX_LENGTH 8
 
int main() {
    float A[MAX_LENGTH];
    int sum = 0;
    float average;
    int i;
    int index = 0;
 

    for (i = 0; i < MAX_LENGTH; i++) {
        printf("", i + 1);
        scanf("%f", &A[i]);
    }
 
  
    for (i = 0; i < MAX_LENGTH; i++) {
        sum += A[i];
    }
    
    average = (float)sum / MAX_LENGTH;
 
    float min_diff = fabs(average - A[0]);
    for (i = 1; i < MAX_LENGTH; i++) {
        float diff = fabs(average - A[i]);
        if (diff < min_diff) {
            min_diff = diff;
            index = i; 
        }
    }
 printf("Trung binh: %.2f\n", average);
 printf("%d %.2f", index, A[index]);
 
    return 0;
}
