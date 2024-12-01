#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int stt;
    char mssv[50];
    char name[100];
    char sdt[20];
    int diem;
} info;

int main()
{
    char line[1024];
    info *students = NULL;
    int n = 0;

   
    FILE *f = fopen("input.txt", "r");
    FILE *g = fopen("bangdiem.txt", "w");

 
    if (f == NULL || g == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, sizeof(line) - 1, f) != NULL)
    {
        info *temp = realloc(students, (n + 1) * sizeof(info));
        if (temp == NULL)
        {
            perror("Error reallocating memory");
            free(students);
            fclose(f);
            fclose(g);
            return 1;
        }
        students = temp;

        memset(&students[n], 0, sizeof(info));

        char *token = strtok(line, " ");
        if (token != NULL)
            students[n].stt = atoi(token);

        token = strtok(NULL, " ");
        if (token != NULL)
            strncpy(students[n].mssv, token, sizeof(students[n].mssv) - 1);

        token = strtok(NULL, " ");
        if (token != NULL)
            strncpy(students[n].name, token, sizeof(students[n].name) - 1);

        token = strtok(NULL, " \n");
        if (token != NULL)
            strncpy(students[n].sdt, token, sizeof(students[n].sdt) - 1);

        n++;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Enter score for student %s: ", students[i].name);
        scanf("%d", &students[i].diem);
    }
  
    for (int i = 0; i < n; i++)
    {
        fprintf(g, "%d %s %s %s %d\n",
                students[i].stt,
                students[i].mssv,
                students[i].name,
                students[i].sdt,
                students[i].diem);
    }

    // Đóng file và giải phóng bộ nhớ
    fclose(g);
    fclose(f);
    free(students);
    return 0;
}
