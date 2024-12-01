#include <stdio.h>
#include <stdbool.h>
#define SIZE 9


bool isSafe(int matrix[SIZE][SIZE], int row, int col, int num) { 
    for (int x = 0; x < SIZE; x++)
        if (matrix[row][x] == num)
            return false;
    for (int x = 0; x < SIZE; x++)
        if (matrix[x][col] == num)
            return false;

    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (matrix[i + startRow][j + startCol] == num)
                return false;
    
    return true;
}

bool findEmptyCell(int matrix[SIZE][SIZE], int* row, int* col) {
    for (*row = 0; *row < SIZE; (*row)++)
        for (*col = 0; *col < SIZE; (*col)++)
            if (matrix[*row][*col] == 0)
                return true;
    return false;
}

bool solveSudoku(int matrix[SIZE][SIZE]) {
    int row, col;
    if (!findEmptyCell(matrix, &row, &col))
        return true;
    for (int num = 1; num <= 9; num++) {
        if (isSafe(matrix, row, col, num)) {
            matrix[row][col] = num;
            if (solveSudoku(matrix))
                return true;
            matrix[row][col] = 0;
        }
    }
    return false;
}

bool isValidSolution(int matrix[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        bool used[SIZE + 1] = {false};
        for (int col = 0; col < SIZE; col++) {
            int num = matrix[row][col];
            if (num < 1 || num > 9 || used[num])
                return false;
            used[num] = true;
        }
    }
    for (int col = 0; col < SIZE; col++) {
        bool used[SIZE + 1] = {false};
        for (int row = 0; row < SIZE; row++) {
            int num = matrix[row][col];
            if (num < 1 || num > 9 || used[num])
                return false;
            used[num] = true;
        }
    }
    for (int box = 0; box < 9; box++) {
        bool used[SIZE + 1] = {false};
        int startRow = (box / 3) * 3;
        int startCol = (box % 3) * 3;
        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int num = matrix[startRow + i][startCol + j];
                if (num < 1 || num > 9 || used[num])
                    return false;
                used[num] = true;
            }
        }
    } 
    return true;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int matrix[SIZE][SIZE];
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++)
                scanf(" %d", &matrix[i][j]);
        if (solveSudoku(matrix)) {
            printf("%d \n", isValidSolution(matrix) ? 1 : 0);
        } else {
            printf("0\n");
        }
    }
}
    
    