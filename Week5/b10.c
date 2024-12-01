#include<stdio.h>

int main(){
    int n, k, m;
    
    scanf("%d %d", &n, &k);
    int A[n][k];
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++) 
            scanf("%d", &A[i][j]);
    }
    
    scanf("%d %d", &k, &m);
    int B[k][m];
    
    for(int i = 0; i < k; i++){
        for(int j = 0; j < m; j++) 
            scanf("%d", &B[i][j]);
    }

    int C[n][m];
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            C[i][j] = 0; 
            for(int y = 0; y < k; y++) {
                C[i][j] += A[i][y] * B[y][j]; 
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
