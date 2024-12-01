#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *f = fopen("input.txt", "r");

    if (f == NULL) {
        perror("Error opening file");
        return -1;
    }

    while (1) {
        printf("1. Copy by character\n");
        printf("2. Copy by line\n");
        printf("3. Copy by block (optional size)\n");
        printf("4. Quit\n");
        printf("Choose an option: ");
        char s[1024] = {0}; // Buffer for block read
        int x;
        scanf("%d", &x);

        clock_t begin = clock();

        // Reset file pointer to the start after each operation
        rewind(f);

        if (x == 1) {
            // Read a single character
            int ch = fgetc(f);
            if (ch != EOF) {
                printf("Character: %c\n", ch);
            } else {
                perror("fgetc");
            }

        } else if (x == 2) {
            // Read a line
            size_t len = 0;
            char *line = NULL;
            ssize_t read = getline(&line, &len, f);

            if (read != -1) {
                printf("Retrieved line of length %zu:\n", read);
                printf("%s", line);
            } else {
                perror("getline");
            }
            free(line);  // Free the memory allocated by getline

        } else if (x == 3) {
            // Read a block of bytes
            int length;
            printf("Enter the number of bytes to be read (max 1024): ");
            scanf("%d", &length);

            if (length > sizeof(s)) {
                length = sizeof(s);
            }

            // Clear the buffer before reading
            memset(s, 0, sizeof(s));

            if (fread(s, 1, length, f) > 0) {
                printf("Block content: %s\n", s);
            } else {
                perror("fread");
            }

        } else if (x == 4) {
            break;
        } else {
            printf("Invalid option\n");
        }

        clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("Elapsed time: %f seconds\n", time_spent);
    }

    fclose(f);
    return 0;
}
