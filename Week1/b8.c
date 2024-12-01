#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {    
    char *s1[] = {"the", "a", "one", "some", "any"};
    char *s2[] = {"boy", "girl", "dog", "town", "car"};
    char *s3[] = {"drove", "jumped", "ran", "walked", "skipped"};
    char *s4[] = {"to", "from", "over", "under", "on"};
    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        int pos1 = rand() % 5; 
        int pos2 = rand() % 5; 
        int pos3 = rand() % 5; 
        int pos4 = rand() % 5; 
        printf("%s %s %s %s.\n", s1[pos1], s2[pos2], s3[pos3], s4[pos4]);
    }

    return 0;
}