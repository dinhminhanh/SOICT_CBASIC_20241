#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  char date[128];
  int count;
} List;

void sort_by_date(List a[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (strcmp(a[j].date, a[i].date) > 0) {
        List tmp = a[j];
        a[j] = a[i];
        a[i] = tmp;
      }
    }
  }
}

int main() {
  List *a = NULL; 
  int n = 0;

  while (1) {
    char str[128];
    int exist = 0;

    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; 

    if (strcmp(str, "*") == 0) {
      break; 
    }

    char *token = strtok(str, " ");
    if (token == NULL) {
      continue; 
    }

    for (int i = 0; i < n; i++) {
      if (strcmp(a[i].date, token) == 0) {
        a[i].count++;
        exist = 1;
        break;
      }
    }

    if (!exist) {
      a = realloc(a, (n + 1) * sizeof(List));
      if (a == NULL) {
        printf("Memory allocation failed\n");
        return 1;
      }

      strcpy(a[n].date, token); 
      a[n].count = 1;
      n++;
    }
  }

  sort_by_date(a, n);
  for (int i = 0; i < n; i++) {
    printf("%s %d\n", a[i].date, a[i].count);
  }

  free(a); 
  return 0;
}
