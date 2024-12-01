#include <stdio.h>
#include <stdbool.h>

#define N 9

int X[N][N];                   
bool markR[N][N+1];             
bool markC[N][N+1];           
bool markS[3][3][N+1];         
int count = 0;                  

void solution() {
    count++;
}

bool check(int v, int r, int c) {
    return !markR[r][v] && !markC[c][v] && !markS[r/3][c/3][v];
}

void try(int r, int c) {
    if (X[r][c] > 0) {
        if (r == 8 && c == 8) {
            solution();
        } else {
            if (c == 8) {
                try(r + 1, 0);
            } else {
                try(r, c + 1);
            }
        }
        return;
    }

    for (int v = 1; v <= 9; v++) {
        if (check(v, r, c)) {
            X[r][c] = v;
            markR[r][v] = 1;
            markC[c][v] = 1;
            markS[r/3][c/3][v] = 1;
            if (r == 8 && c == 8) {
                solution();
            } else {
                if (c == 8) {
                    try(r + 1, 0);
                } else {
                    try(r, c + 1);
                }
            }

            markR[r][v] = 0;
            markC[c][v] = 0;
            markS[r/3][c/3][v] = 0;
            X[r][c] = 0;
        }
    }
}

int main() {

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++) {
            markR[i][j] = 0;
            markC[i][j] = 0;
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k <= N; k++) {
                markS[i][j][k] = 0;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &X[i][j]);
            if (X[i][j] > 0) {
                int v = X[i][j];
                markR[i][v] = 1;
                markC[j][v] = 1;
                markS[i/3][j/3][v] = 1;
            }
        }
    }

    try(0, 0);
    printf("%d\n", count);
    return 0;
}