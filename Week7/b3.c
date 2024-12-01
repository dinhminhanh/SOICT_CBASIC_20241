#include <stdio.h>
#include <limits.h>

int N, M;
int x[25] = {0};        
int d[25][25] = {0};      
int mark[100] = {0};      
int f = 0;                
int f_min = INT_MAX;      
int Cm; 
int count = 0;                 

void input(){
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++) {
            scanf("%d", &d[i][j]);
            if (i != j && d[i][j] < Cm) {
                Cm = d[i][j];
            }
        }
    }
}

void Try(int k){
    for (int v = 1; v <= N; v++){
        if (mark[v] == 0) {
            x[k] = v;
            f = f + d[x[k-1]][v];
            mark[v] = 1;
            
            if (k == N) {
                int cost = f + d[x[N]][x[1]];
                if (cost <=  M) {
                    count +=1;
                }
            }
            else {
                if (f + Cm*(N-k+1) <= M) {
                    Try(k+1);
                }
            }
            mark[v] = 0; 
            f = f - d[x[k-1]][v];
        }
    }
}

int main(){
    Cm = INT_MAX;
    input();
    x[1] = 1;
    mark[1] = 1;  
    Try(2);
    printf("%d\n", count);
    
    return 0;
}