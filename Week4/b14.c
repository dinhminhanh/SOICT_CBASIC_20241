#include <stdio.h>

int M, T, n;
int x[105], a[105];

void try(int k) {
  if(k == n && T == M) { 
    for (int i = 0; i < n - 1; i++) {
      printf("%d*%d + ", x[i], a[i]);
    }
    printf("%d*%d \n", x[n - 1], a[n - 1]);
    return;
  }
  
  if (k == n) return; 
  
  for(int i = 1; i <= M; i++) { 
    if(T + i * a[k] <= M) {
      T += i * a[k];
      x[k] = i;
      try(k + 1); 
      T -= i * a[k];
    }
  }
}

int main() {
  scanf("%d %d", &M, &n);
  
  for(int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  try(0);
}
