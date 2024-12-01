#include <stdio.h>
#include <limits.h>

int n;
int x[25] = {0};        
int d[25][25] = {0};      
int mark[100] = {0};      
int f = 0;                
int f_min = INT_MAX;      
int Cm;                   

void input(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++) {
            scanf("%d", &d[i][j]);
            if (i != j && d[i][j] < Cm) {
                Cm = d[i][j];
            }
        }
    }
}

void Try(int k){
    for (int v = 1; v <= n; v++){
        if (mark[v] == 0) {
            x[k] = v;
            f = f + d[x[k-1]][v];
            mark[v] = 1;
            
            if (k == n) {
                int cost = f + d[x[n]][x[1]];
                if (f_min >  cost) {
                    f_min =  cost;
                }
            }
            else {
                if (f + Cm*(n-k+1) < f_min) {
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
    printf("%d\n", f_min);
    return 0;
}