#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 50
#define PHONE_LENGTH 15

typedef struct {
    int stt;
    char mssv[10];
    char name[NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    float score;
} Student;

Student* readStudentList(const char* filename, int* count) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Can not open file %s\n", filename);
        return NULL;
    }

    Student* students = NULL;
    *count = 0;
    char line[100];

    while (fgets(line, sizeof(line), file)) {
        (*count)++;
        students = (Student*)realloc(students, (*count) * sizeof(Student));
        
        sscanf(line, "%d %s %s %s", &students[*count-1].stt, 
               students[*count-1].mssv, students[*count-1].name, 
               students[*count-1].phone);
        students[*count-1].score = -1; 
    }

    fclose(file);
    return students;
}

// input scores for students
void inputScores(Student* students, int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter score for student %s: ", students[i].name);
        scanf("%f", &students[i].score);
    }
}

//add new students
Student* addNewStudents(Student* students, int* count) {
    int newCount;
    printf("Enter the number of students to add: ");
    scanf("%d", &newCount);

    int oldCount = *count;
    *count += newCount;
    students = (Student*)realloc(students, (*count) * sizeof(Student));

    for (int i = oldCount; i < *count; i++) {
        students[i].stt = i + 1;
        printf("Enter details for student %d:\n", i + 1);
        printf("Student ID (MSSV): ");
        scanf("%s", students[i].mssv);
        printf("Full name: ");
        scanf("%s", students[i].name);
        printf("Phone number: ");
        scanf("%s", students[i].phone);
        printf("Score: ");
        scanf("%f", &students[i].score);
    }

    return students;
}

void writeTranscript(const char* filename, Student* students, int count) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Can not open file %s for writing\n", filename);
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d %s %s %s %.2f\n", students[i].stt, students[i].mssv, 
                students[i].name, students[i].phone, students[i].score);
    }

    fclose(file);
    printf("Transcript has been saved to file %s\n", filename);
}

int main() {
    int count;
    Student* students = readStudentList("bangdiem.txt", &count);
    if (students == NULL) {
        return 1;
    }

    printf("%d students have been read from the file.\n", count);

    inputScores(students, count);

    students = addNewStudents(students, &count);

    writeTranscript("transcript.txt", students, count);

    free(students);
    return 0;
}
