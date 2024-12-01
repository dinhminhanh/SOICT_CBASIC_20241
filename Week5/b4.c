#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
    char s1[50], s2[50], T[100];
    fgets(s1, sizeof(s1), stdin);
    fgets(s2, sizeof(s2), stdin);
    fgets(T, sizeof(T), stdin);

    T[strcspn(T, "\n")] = 0;
    s1[strcspn(s1, "\n")] = 0;
    s2[strcspn(s2, "\n")] = 0;

    char *token = strtok(T, " ");
    
    while (token != NULL) {
        if(strcmp(token, s1) == 0) {
            printf("%s ", s2);
        } else {
            printf("%s ", token);
        }
        token = strtok(NULL, " ");
    }

    return 0;
}
