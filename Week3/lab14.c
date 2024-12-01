#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENT 20

typedef struct phoneaddress {
  char name[20];
  char tel[11];
  char email[25];
} phoneaddress;

int main(void) {
  FILE *fp;
  phoneaddress *phonearr;
  int from, to;

  if ((fp = fopen("phonebook.dat", "r+b")) == NULL) {
    printf("Can not open %s.\n", "phonebook.dat");
    return -1;
  }

  printf("Read data <from> <to>: ");
  scanf("%d %d", &from, &to);

  phonearr = (phoneaddress *)malloc((to - from + 1) * sizeof(phoneaddress));

  fseek(fp, (from - 1) * sizeof(phoneaddress), SEEK_SET);

  fread(phonearr, sizeof(phoneaddress), (to - from + 1), fp);

  for (int i = 0; i < (to - from + 1); i++) {
    printf("Name: %s\n", phonearr[i].name);
    printf("Phone: %s\n", phonearr[i].tel);
    printf("Mail: %s\n", phonearr[i].email);
  }

  char mail[25];
  printf("Enter new mail: ");
  getchar();  
  fgets(mail, sizeof(mail), stdin);
  mail[strcspn(mail, "\n")] = '\0'; 

  for (int i = 0; i < (to - from + 1); i++) {
    strcpy(phonearr[i].email, mail);
  }

  fseek(fp, (from - 1) * sizeof(phoneaddress), SEEK_SET);
  fwrite(phonearr, sizeof(phoneaddress), (to - from + 1), fp);

  printf("Email changed successfully!\n"); 
  fclose(fp);
  free(phonearr);
  
  return 0;
}
