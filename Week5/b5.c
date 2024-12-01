#include<stdio.h>
int T[1005][1005];
int main(){
   int n,m;
   
   int ans =0;
   
   scanf("%d %d", &n, &m);

   for (int i =0; i <n; i++){
    for(int j=0; j < m ; j++) scanf("%d", &T[i][j]);
   } 

   for(int j =0 ; j<m; j++){
    int cnt = 0;
    for(int i=0; i <n; i++){
        if(T[i][j] == 1) cnt++;
    }
    if(cnt == n) ans++;

   }
   printf("%d\n", ans);
   return 0;
}