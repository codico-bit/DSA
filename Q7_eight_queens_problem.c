// Write a program to solve the eight queens problem on an 8×8 chessboard.
#include <stdio.h>

void displayBoard(int n, int board[n][n]) {
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            printf("%d ", board[row][col]);
        }
        printf("\n");
    }
}

int isValid(int n, int board[n][n], int curr_row, int curr_col) {
    for (int i = 0; i < curr_col; i++) {
        if (board[curr_row][i]) return 0;
    }
    for (int i = curr_row, j = curr_col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) return 0;
    }
    for (int i = curr_row, j = curr_col; j >= 0 && i < n; i++, j--) {
        if (board[i][j]) return 0;
    }
    return 1;
}

int solveNQueens(int n, int board[n][n], int curr_col) {
    if (curr_col >= n) return 1;
    for (int i = 0; i < n; i++) {
        if (isValid(n, board, i, curr_col)) {
            board[i][curr_col] = 1;
            if (solveNQueens(n, board, curr_col + 1)) return 1;
            board[i][curr_col] = 0;
        }
    }
    return 0;
}

int main() {
    int n;
    printf("Enter n, the length of each side of the chessboard: ");
    scanf("%d", &n);
    int board[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = 0;
        }
    }
    if (solveNQueens(n, board, 0) == 0) {
        printf("Solution does not exist\n");
        return 0;
    }
    displayBoard(n, board);
    return 0;
}
