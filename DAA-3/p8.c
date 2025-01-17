//	Implement the N Queen problem.

#include <stdio.h>
#include <stdbool.h>

#define N 8 

void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", board[i][j] ? 'Q' : '.');
        }
        printf("\n");
    }
    printf("\n");
}


bool isSafe(int board[N][N], int row, int col) {
    
    for (int i = 0; i < row; i++) {
        if (board[i][col]) {
            return false;
        }
    }

   
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}


bool solveNQueen(int board[N][N], int row) {

    if (row >= N) {
        printSolution(board);
        return true;
    }

    
    bool res = false;
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1; 
            
            res = solveNQueen(board, row + 1) || res;

            
            board[row][col] = 0;
        }
    }

    return res;
}

int main() {
    int board[N][N] = {0};

    if (!solveNQueen(board, 0)) {
        printf("No solution exists.\n");
    }

    return 0;
}
