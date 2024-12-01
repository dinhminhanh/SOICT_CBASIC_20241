#include <stdio.h>

int Even(int sum) {
    return sum % 2 == 0;
}

int main() {
    int n, k;
    int count = 0;
    scanf("%d %d", &n, &k);

    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i <= n - k; i++) {
        int sum = 0;
        for (int j = 0; j < k; j++) {
            sum += a[i + j];
        }
        if (Even(sum)) {
            count++;
        }
    }

    printf("%d\n", count);
    return 0;
}
