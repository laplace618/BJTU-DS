#include <stdio.h>
#include <stdbool.h>

#define N 8

int board[N][N];

bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

void printSolution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1) {
                printf(" Q ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

bool solveNQueens(int row) {
    if (row == N) {
        printSolution();
        return true;
    }

    bool res = false;
    for (int i = 0; i < N; i++) {
        if (isSafe(row, i)) {
            board[row][i] = 1;
            res = solveNQueens(row + 1) || res;
            board[row][i] = 0;
        }
    }

    return res;
}

int main() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }

    if (!solveNQueens(0)) {
        printf("No solution exists.\n");
    }

    return 0;
}
