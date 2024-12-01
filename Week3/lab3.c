#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100
char *my_strcat(char *str1, char *str2){
    int len1, len2;
    char *str;
    len1=strlen(str1);
    len2=strlen(str2);
    str = (char*)malloc((len1 + len2 + 1) * sizeof(char));
    if (str == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    strcpy(str, str1);
    strcpy(str + len1, str2);
    return str;
   
}

int main(){
    char str1[MAX_LEN + 1], str2[MAX_LEN + 1];
    char* cat_str;
    scanf("%100s", str1);
    scanf("%100s", str2);

    cat_str = my_strcat(str1,str2);
    if (cat_str == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    printf("%s\n",cat_str);
    free(cat_str);
    return 0;
}