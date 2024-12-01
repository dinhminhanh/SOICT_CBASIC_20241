#include <stdio.h>

int x[100005], n;

void try(int k) {
  if(k == n) {
    for(int i = 0; i < n; i++) {
      printf("%d", x[i]);
    }
    printf("\n");
    return;
  }

  for(int i = 0; i <= 1; i++) {
    x[k] = i;
    try(k + 1);
  }
}

int main() {
  scanf("%d", &n);
  try(0);
}