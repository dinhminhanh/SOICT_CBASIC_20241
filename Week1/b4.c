#include <stdio.h>
#include <string.h>

int main() {
    int count[50] = {0}; 
    char s[100]  ;
    fgets(s, sizeof(s), stdin);

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') { 
            count[s[i] - 'a']++;
        }
    }

    
    for (int i = 0; i < 50; i++) {
        if (count[i] > 0) {
            printf("The letter '%c' appears %d time(s).\n", 'a' + i, count[i]);
        }
    }

    return 0;
}
