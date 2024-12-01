#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
    if(argc < 2) {
    printf("Please re-enter");
    return 1;
    }
    for (int i = argc -1 ; i > 0 ; i--){
        printf("%s ", argv[i]);
    }
    return 0;
}
