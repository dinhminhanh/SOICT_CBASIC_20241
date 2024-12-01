#include <stdio.h>

int x[100], n;

void try(int k, int v) {
  if(k == n) {
    for(int i = 0; i < n; i++) {
      printf("%d", x[i]);
    }
    printf("\n");
    return;
  }

  for(int i = 0; i <= 1; i++) {
    x[k] = i;
    if(i == 0 || v == 0)
      try(k + 1, i);
  }
}

int main() {
  scanf("%d", &n);
  try(0, 0);
}