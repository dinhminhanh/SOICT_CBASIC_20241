#include <stdio.h>
#include <stdbool.h>

int a[10][10], cnt = 0;
bool markR[10][10], markC[10][10], markS[3][3][10];

bool check(int i, int j, int k)
{
    return (markR[i][k] == false) && (markC[j][k] == false) && (markS[i/3][j/3][k] == false);
}

void try(int i, int j) 
{
    if(a[i][j] != 0)
    {
        if(i == 8 && j == 8)
            ++cnt;
        else
        {
            if(j < 8) try(i, j+1); 
            else try(i+1, 0);   
        }
    }
    else
    {
        for(int k = 1; k <= 9; k++)
        {
            if(check(i, j, k))
            {
                markR[i][k] = true;
                markC[j][k] = true;
                markS[i/3][j/3][k] = true;

                if(i == 8 && j == 8)
                    ++cnt;
                else
                {
                    if(j < 8) try(i, j+1); 
                    else try(i+1, 0);  
                }

                markR[i][k] = false;
                markC[j][k] = false;
                markS[i/3][j/3][k] = false;
            }
        }
    }
}

int main()
{
    for(int i = 0; i <= 8; i++) 
    {
        for(int j = 0; j <= 8; j++) 
        {
            scanf("%d", &a[i][j]);
            markR[i][a[i][j]] = true;
            markC[j][a[i][j]] = true;
            markS[i/3][j/3][a[i][j]] = true;
        }
    }

    try(0, 0);
    printf("%d\n", cnt);

    return 0;
}
