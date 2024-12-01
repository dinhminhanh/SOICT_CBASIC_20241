#include <stdio.h>
#define MAX_SIZE 100 

int compare_arrays(int array1[], int array2[], int size) {
    int count = 0; 
    int is_reverse = 1; 
 
    
    for (int i = 0; i < size; i++) {
        if (array1[i] == array2[i]) {
            count++; 
        }
        
        if (array1[i] != array2[size - 1 - i]) {
            is_reverse = 0; 
        }
    }
 
    if (count == size) {
        return 1; 
    }
    
    
    if (is_reverse) {
        return -1; 
    }
 
    
    return 0; 
}
 
int main(void) {
    int n;
    scanf("%d", &n);
 
    int input1[MAX_SIZE]; 
    int input2[MAX_SIZE]; 

    for (int i = 0; i < n; ++i) {
        scanf("%d", &input1[i]);
    }
 
    for (int i = 0; i < n; ++i) {
        scanf("%d", &input2[i]);
    }
 
    int result = compare_arrays(input1, input2, n);
    printf("%d\n", result);
 
    return 0;
}
 