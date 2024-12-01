#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char** argv) {
    if (argc < 2) {    
        return 1;
    }
        
    float x = atof(argv[1]);    
    float sai_so = argc == 3 ? atof(argv[2]) : 0;
    
    float ans = 1, bot = 1, top = 1;
    float ex = expf(x);
        
    for (int i = 1; i <= 100; i++) {
        top *= x;          
        bot *= (float)i;   
        ans += top / bot; 
        
        if (fabsf(ans - ex) <= sai_so)
            break;
    }

    printf("e^%.2f ~ %f (sai so %f)\n", x, ans, sai_so);
    return 0;
}