#include <stdio.h>

int main() {
    int n;
    int x1, y1, x2, y2;
    int x_min = 101;  
    int y_min = 101;
    int x_max = 0;  
    int y_max = 0;   
    
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        
        if (x1 < x_min) x_min = x1;
        if (x2 < x_min) x_min = x2;
        if (x1 > x_max) x_max = x1;
        if (x2 > x_max) x_max = x2;
        
        if (y1 < y_min) y_min = y1;
        if (y2 < y_min) y_min = y2;
        if (y1 > y_max) y_max = y1;
        if (y2 > y_max) y_max = y2;
    }
    
    int area = (x_max - x_min) * (y_max - y_min);
    printf("%d\n", area);
    
    return 0;
}