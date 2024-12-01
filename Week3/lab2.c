#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *str1, *str2, *str;
    int len;
    str1 = (char *)malloc(40);
    str2 = (char *)malloc(40);

    if (str1 == NULL || str2 == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    fgets(str1, 40, stdin);
    str1[strcspn(str1, "\r\n")] = '\0'; 
    fgets(str2, 40, stdin);
    str2[strcspn(str2, "\r\n")] = '\0';

    str = (char *)malloc(40);
    if (str == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        free(str1);
        free(str2);
        return 1;
    }
    strcpy(str, str1);

    str = (char *)realloc(str, 80);

    strcat(str, str2);
    len = strlen(str);
    printf("%d %s\n", len, str);
    free(str1);
    free(str2);
    free(str);
    return 0;
}