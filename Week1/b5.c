#include<stdio.h>
#include<string.h>

void replace(char str[], char replace_what, char replace_with){
for(int i =0; i < strlen(str); i++){
    if(str[i] == replace_what){
        str[i] = replace_with;
    }
}
}

int main(){
   char str[100], replace_what, replace_with;
   scanf("%s %c %c", str,&replace_what,&replace_with);
   replace(str, replace_what, replace_with);
   printf("%s", str);
   return 0;
}