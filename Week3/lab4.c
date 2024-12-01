#include <stdio.h>
#include <stdlib.h>

int str_len(const char* s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

char* subStr(char* s1, int offset, int number) {
    int len = str_len(s1);

    if (offset < 0 || offset >= len) {
        return NULL;
    }
    
    if (offset + number > len) {
        number = len - offset;
    }
    
    char* result = (char*)malloc((number + 1) * sizeof(char));
    if (result == NULL) {
        return NULL;
    }
    
    for (int i = 0; i < number; i++) {
        result[i] = s1[offset + i];
    }
    result[number] = '\0';
    
    return result;
}

int main() {
    int offset, number;
    char str[81] = {0}; 
    if (scanf("%d %d\n", &offset, &number) != 2) {
        printf("Error: Invalid input for offset and number.\n");
        return 1;
    }

    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error: Unable to read input string.\n");
        return 1;
    }
    int len = str_len(str);
    if (len > 0 && str[len-1] == '\n') {
        str[len-1] = '\0';
    }
    char* sub = subStr(str, offset, number);

    if (sub != NULL) {
        printf("-%s-\n-%s-\n", str, sub);
        free(sub);  // Giải phóng bộ nhớ
    } else {
        printf("Error: Unable to create substring.\n");
    }

    return 0;
}