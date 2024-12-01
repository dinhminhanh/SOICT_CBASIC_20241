#include <stdio.h>

int n, x[105];
int used[105];

void back(int k)
{
  for (int i = 1; i <= n; i++)
  {
    if (!used[i])
    {
      x[k] = i;
      used[i] = 1;
      if (k == n)
      {
        for (int j = 1; j <= n; j++)
          printf("%d ", x[j]);
        printf("\n");
      }
      else
        back(k + 1);
      used[i] = 0;
    }
  }
}

int main()
{
  scanf("%d", &n);
  back(1);
}
