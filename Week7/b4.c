#include <stdio.h>
#define MAX 1001
#define INF 1000000

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int n, x;
    int coins[MAX];
    int dp[MAX];

    scanf("%d %d", &n, &x);
    for(int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }
    
    for(int i = 0; i <= x; i++) {
        dp[i] = INF;
    }
    dp[0] = 0; 
    
    for(int i = 1; i <= x; i++) {
        for(int j = 0; j < n; j++) {
            if(coins[j] <= i) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    printf("%d\n", dp[x] == INF ? -1 : dp[x]);
    return 0;
}