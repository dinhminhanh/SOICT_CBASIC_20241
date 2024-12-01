#include<stdio.h>
#include <string.h>

int main() {
    char str[100];
    fgets(str, sizeof(str), stdin);  
    //str[strcspn(str, "\n")] = 0; 

    int index = 0;
    int len = strlen(str);

    for (int i = 0; i <= len; i++) {
        if (str[i] == ' ' || str[i] == '\0') {
            printf("%.*s\n", i - index, &str[index]);           
            index = i + 1;
        }
    }

    return 0;
}