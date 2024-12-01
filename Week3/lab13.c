#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
#define MAX_ID 10

typedef struct {
    char id[MAX_ID];
    char name[MAX_NAME];
    float grade;
} Student;

Student* students = NULL;
int count = 0;

void textToDat() {
    FILE *file1 = fopen("bangdiem.txt", "r");
    if (file1 == NULL) {
        printf("Cannot open bangdiem.txt\n");
        return;
    }
    
    // Read the number of students
    if (fscanf(file1, "%d", &count) != 1) {
        printf("Error reading student count\n");
        fclose(file1);
        return;
    }

    // Allocate memory for students
    students = (Student*)malloc(count * sizeof(Student));
    if (students == NULL) {
        printf("Memory allocation failed\n");
        fclose(file1);
        return;
    }

    // Read student data
    for (int i = 0; i < count; i++) {
        if (fscanf(file1, "%s %s %f", students[i].id, students[i].name, &students[i].grade) != 3) {
            printf("Error reading data for student %d\n", i + 1);
            free(students);
            fclose(file1);
            return;
        }
    }
    fclose(file1);

    // Write to the binary file
    FILE *file2 = fopen("grade.dat", "wb");
    if (file2 == NULL) {
        printf("Cannot create grade.dat\n");
        free(students); // Free allocated memory
        return;
    }

    fwrite(&count, sizeof(int), 1, file2);
    fwrite(students, sizeof(Student), count, file2);
    fclose(file2);
    
    printf("Successfully converted from bangdiem.txt to grade.dat\n");
}

void displayDatFile() {
    FILE *file2 = fopen("grade.dat", "rb");
    if (file2 == NULL) {
        printf("Cannot open grade.dat\n");
        return;
    }

    fread(&count, sizeof(int), 1, file2);

    // Allocate memory for students
    if (students != NULL) free(students);
    students = (Student*)malloc(count * sizeof(Student));
    if (students == NULL) {
        printf("Memory allocation failed\n");
        fclose(file2);
        return;
    }

    fread(students, sizeof(Student), count, file2);
    fclose(file2);
    
    printf("Student transcript:\n");
    for (int i = 0; i < count; i++) {
        printf("%s %s %.2f\n", students[i].id, students[i].name, students[i].grade);
    }
}

void searchAndUpdate() {
    char searchId[MAX_ID];
    printf("Enter student ID: ");
    scanf("%s", searchId);

    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].id, searchId) == 0) {
            printf("Student: %s %s %.2f\n", students[i].id, students[i].name, students[i].grade);
            
            printf("Enter new score: ");
            scanf("%f", &students[i].grade);

            // Write the updated data back to the binary file
            FILE *file2 = fopen("grade.dat", "wb");
            if (file2 == NULL) {
                printf("Cannot open grade.dat for update\n");
                return;
            }

            fwrite(&count, sizeof(int), 1, file2);
            fwrite(students, sizeof(Student), count, file2);
            fclose(file2);

            printf("Score updated and saved to file\n");
            return;
        }
    }

    printf("No student found with ID %s\n", searchId);
}

int main() {
    int choice;

    do {
        printf("Menu:\n");
        printf("1. TextToDat\n");
        printf("2. Display Dat file\n");
        printf("3. Search and Update\n");
        printf("4. Quit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                textToDat();
                break;
            case 2:
                displayDatFile();
                break;
            case 3:
                searchAndUpdate();
                break;
            case 4:
                break;
            default:
                printf("Please select again.\n");
        }
    } while (choice != 4);

    if (students != NULL) free(students);

    return 0;
}
