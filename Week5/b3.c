#include <stdio.h>

int Try(int a[], int b[], int n, int i) {
    if (n == i) return 1;
    if (a[i] != b[i]) return 0;
    return Try(a, b, n, i + 1);
}

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        int n, m;
        scanf("%d %d", &n, &m);

        int a[n], b[m];

        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int j = 0; j < m; j++) {
            scanf("%d", &b[j]);
        }

        if (n != m) {
            printf("0\n");
        } else {
            if (Try(a, b, n, 0)) {
                printf("1\n");
            } else {
                printf("0\n");
            }
        }
    }
    return 0;
}
