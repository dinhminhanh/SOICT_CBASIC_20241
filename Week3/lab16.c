#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MODEL_LENGTH 30
#define MAX_LINE_LENGTH 1024
#define INITIAL_CAPACITY 10

typedef struct {
    char model[MAX_MODEL_LENGTH];
    int memory;
    float screen_size;
    float price;
} Phone;

int n = 0;
int capacity = INITIAL_CAPACITY;
Phone *phone = NULL;

// Function prototypes
char **split_line(char *line);
void import_db_from_text(FILE *fbin, FILE *ftext);
void import_db_from_file(FILE *fbin);
void print_all_records(void);
void search_by_model(void);

char **split_line(char *line) {
    int pos = 0, bufsize = 64;
    char **result = malloc(bufsize * sizeof(char *));
    if (!result) {
        perror("malloc");
        return NULL;
    }
    char *token = strtok(line, " ");

    while (token != NULL) {
        result[pos++] = token;
        if (pos >= bufsize) {
            bufsize += 64;
            char **temp = realloc(result, bufsize * sizeof(char *));
            if (!temp) {
                perror("realloc");
                free(result);
                return NULL;
            }
            result = temp;
        }
        token = strtok(NULL, " ");
    }
    result[pos] = NULL;
    return result;
}

void import_db_from_text(FILE *fbin, FILE *ftext) {
    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), ftext) != NULL) {
        line[strcspn(line, "\n")] = '\0';
        char **result = split_line(line);

        if (result == NULL) {
            return;
        }

        if (n >= capacity) {
            capacity *= 2;
            Phone *temp = realloc(phone, capacity * sizeof(Phone));
            if (!temp) {
                perror("realloc");
                free(result);
                return;
            }
            phone = temp;
        }

        strncpy(phone[n].model, result[0], MAX_MODEL_LENGTH - 1);
        phone[n].model[MAX_MODEL_LENGTH - 1] = '\0';
        phone[n].memory = atoi(result[1]);
        phone[n].screen_size = atof(result[2]);
        phone[n].price = atof(result[3]);

        n++;

        free(result);
    }

    fwrite(phone, sizeof(Phone), n, fbin);
}

void import_db_from_file(FILE *fbin) {
    int choice;
    printf("Choose the reading mode:\n");
    printf("1. Read all\n");
    printf("2. Read <from> <to>\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar(); // Consume newline

    if (choice == 1) {
        // Read all data
        fseek(fbin, 0, SEEK_END);
        long file_size = ftell(fbin);
        rewind(fbin);

        int record_count = file_size / sizeof(Phone);

        if (record_count > capacity) {
            capacity = record_count;
            Phone *temp = realloc(phone, capacity * sizeof(Phone));
            if (!temp) {
                perror("realloc");
                return;
            }
            phone = temp;
        }

        size_t read = fread(phone, sizeof(Phone), record_count, fbin);
        if (read != record_count) {
            perror("fread");
            return;
        }

        n = record_count;
        printf("Successfully read all %d records!\n", n);
    } else if (choice == 2) {
        // Read partial data
        int from, to;
        printf("Enter the range to read (from to): ");
        if (scanf("%d %d", &from, &to) != 2 || from < 0 || to < from) {
            printf("Invalid range. Please enter valid 'from' and 'to' values.\n");
            while (getchar() != '\n'); // Clear input buffer
            return;
        }
        getchar(); // Consume newline

        fseek(fbin, 0, SEEK_END);
        long file_size = ftell(fbin);
        int total_records = file_size / sizeof(Phone);

        if (to >= total_records) {
            to = total_records - 1;
            printf("Adjusted 'to' to %d (last record)\n", to);
        }

        int records_to_read = to - from + 1;

        if (records_to_read > capacity - n) {
            capacity += records_to_read;
            Phone *temp = realloc(phone, capacity * sizeof(Phone));
            if (!temp) {
                perror("realloc");
                return;
            }
            phone = temp;
        }

        fseek(fbin, from * sizeof(Phone), SEEK_SET);
        size_t read = fread(phone + n, sizeof(Phone), records_to_read, fbin);
        if (read != records_to_read) {
            perror("fread");
            return;
        }

        n += records_to_read;
        printf("Successfully read %d records from position %d to %d!\n", records_to_read, from, to);
    } else {
        printf("Invalid choice. Please enter 1 or 2.\n");
    }
}

void print_all_records(void) {
    printf("%-20s %-10s %-20s %-10s\n", "Model", "Memory(GB)", "Screen Size", "Price");
    for (int i = 0; i < n; i++) {
        printf("%-20s %-10d %-20.2f %-10.2f\n", phone[i].model, phone[i].memory, phone[i].screen_size, phone[i].price);
    }
    printf("Successfully displayed all records!\n");
}

void search_by_model(void) {
    char model[MAX_MODEL_LENGTH];
    printf("Search by model: ");
    fgets(model, sizeof(model), stdin);
    model[strcspn(model, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(model, phone[i].model) == 0) {
            printf("%-20s %-10d %-20.2f %-10.2f\n", phone[i].model, phone[i].memory, phone[i].screen_size, phone[i].price);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Phone model not found!\n");
    } else {
        printf("Successfully found the phone model!\n");
    }
}

int main() {
    FILE *ftext = fopen("PhoneDB.txt", "r");
    FILE *fbin = fopen("PhoneDB.dat", "ab+");

    if (ftext == NULL || fbin == NULL) {
        perror("fopen");
        return -1;
    }

    phone = malloc(capacity * sizeof(Phone));
    if (!phone) {
        perror("malloc");
        fclose(ftext);
        fclose(fbin);
        return -1;
    }

    while (1) {
        int cmd;
        printf("\nMenu:\n");
        printf("1. Import DB from text\n");
        printf("2. Import DB from file\n");
        printf("3. Print all records\n");
        printf("4. Search by phone\n");
        printf("5. Exit\n");
        printf("Choose an option: ");

        if (scanf("%d", &cmd) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }
        getchar(); // Consume newline

        switch (cmd) {
            case 1:
                import_db_from_text(fbin, ftext);
                printf("Successfully imported database from text file!\n");
                break;
            case 2:
                import_db_from_file(fbin);
                break;
            case 3:
                print_all_records();
                break;
            case 4:
                search_by_model();
                break;
            case 5:
                fclose(ftext);
                fclose(fbin);
                free(phone);
                printf("Exited program successfully!\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}