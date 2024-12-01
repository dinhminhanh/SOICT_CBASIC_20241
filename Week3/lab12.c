#include<stdio.h>
#define MAX_ELEMENT 100
enum {SUCCESS, FAIL};

typedef struct phoneaddress_t {
    char name[20];
    char tel[11];
    char email[25];
} phoneaddress;

int main(){
    int n;
    int write, read;
    int reval = SUCCESS;  
    FILE* fp;
    phoneaddress phone[MAX_ELEMENT];
    
    printf("How many contacts do you want to enter: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        printf("Name: "); scanf("%s", phone[i].name);
        printf("Tel: "); scanf("%s", phone[i].tel);
        printf("Email: "); scanf("%s", phone[i].email);
    }
    
    if ((fp = fopen("phonebook.dat", "w+b")) == NULL) {
        printf("Cannot open %s.\n", "phonebook.dat");
        reval = FAIL;
        return reval;
    }
    
    write = fwrite(phone, sizeof(phoneaddress), n, fp);
    printf("Write successful\n");
    fclose(fp);
    
    if ((fp = fopen("phonebook.dat", "rb")) == NULL) {
        printf("Cannot open %s.\n", "phonebook.dat");
        reval = FAIL;
        return reval;
    }

    read = fread(phone, sizeof(phoneaddress), n, fp);
    printf("Read successful\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s - ", phone[i].name);
        printf("Tel: %s - ", phone[i].tel);
        printf("Email: %s\n", phone[i].email);
    }

    fclose(fp);
    return reval;
}
