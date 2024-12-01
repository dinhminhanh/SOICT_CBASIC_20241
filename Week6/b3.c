#include <stdio.h>
#include <stdbool.h>
#define MAX_N 100

int n;                    
int x[MAX_N];           
bool mark[MAX_N];        
bool markD1[2 * MAX_N];  
bool markD2[2 * MAX_N];  
bool found;              

bool check(int r, int k) {
    return !mark[r] && !markD1[n + k - r] && !markD2[k + r];
}

void try_queen(int k) {
    if (found || k >= n) return;
    
    if (x[k] >= 0) {
        int r = x[k];
        if (!check(r, k)) {
            return;
        }
        mark[r] = true;
        markD1[n + k - r] = true;
        markD2[k + r] = true;
        
        if (k == n - 1) {
            found = true;
            return;
        }   
        try_queen(k + 1);  
        if (!found) {
            mark[r] = false;
            markD1[n + k - r] = false;
            markD2[k + r] = false;
        }
        return;
    }
    
    for (int r = 0; r < n; r++) {
        if (check(r, k)) {
            x[k] = r;
            mark[r] = true;
            markD1[n + k - r] = true;
            markD2[k + r] = true;
            
            if (k == n - 1) {
                found = true;
                return;
            } 
            try_queen(k + 1); 
            if (found) return;
    
            x[k] = -1;
            mark[r] = false;
            markD1[n + k - r] = false;
            markD2[k + r] = false;
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int test = 1; test <= T; test++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int cell;
                scanf("%d", &cell);
                if (cell == 1) {
                    x[j] = i;  // Lưu vị trí quân hậu từ input
                } else if (j == 0) {
                    x[j] = -1; // Khởi tạo cho cột chưa có quân hậu
                }
            }
        }
        found = false;
        for (int i = 0; i < n; i++) {
            mark[i] = false;
        }
        for (int i = 0; i < 2 * n; i++) {
            markD1[i] = false;
            markD2[i] = false;
        }
        try_queen(0);
        printf("%d\n", found ? 1 : 0);
    }  
    return 0;
}
