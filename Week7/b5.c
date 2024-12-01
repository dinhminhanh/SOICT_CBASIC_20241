#include <stdio.h>
#define MAX_N 101
#define MAX_M 10001
#define MOD 1000000007

long long dp[MAX_N][MAX_M];
int main() {
    int n, M;
    int a[MAX_N];

    scanf("%d %d", &n, &M);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
   
    dp[0][0] = 1;
    for(int j = 1; j <= M; j++) {
        dp[0][j] = 0;
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= M; j++) {
            dp[i][j] = dp[i-1][j]; 
            
            int k = 1;
            while(j >= k * a[i]) {
                dp[i][j] = (dp[i][j] + dp[i-1][j - k * a[i]]) % MOD;
                k++;
            }
        }
    }
    
    printf("%lld\n", dp[n][M]);    
    return 0;
}