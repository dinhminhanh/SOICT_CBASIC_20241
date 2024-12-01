#include <stdio.h>

int n, cnt, x[105];
int row[105], col[105], plus[105], minus[105];

void Try(int k) {
  for(int i = 1; i <= n; i++) {
    if(!row[k] && !col[i] && !plus[i + k - 1] && !minus[i - k + n]) {
      x[k] = i;
      row[k] = 1;
      col[i] = 1;
      plus[i + k - 1] = 1;
      minus[i - k + n] = 1;

      if(k < n) {
        Try(k + 1);
      } else {
        for(int v = 1; v <= n; v++) {
          printf("%d ", x[v]);
        }
        printf("\n");
      }

      row[k] = 0;
      col[i] = 0;
      plus[i + k - 1] = 0;
      minus[i - k + n] = 0;
    }
  }
}

int main() {
  scanf("%d", &n);
  Try(1);
}