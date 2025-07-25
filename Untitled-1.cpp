#include <iostream>
#include <vector>
using namespace std;
#define N 9

void printBoard(const vector<vector<int>>& board) {
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++)
            cout << board[r][c] << " ";
        cout << "\n";
    }
}

// Check if num can go at (row, col)
bool isSafe(const vector<vector<int>>& mat, int row, int col, int num) {
    for (int x = 0; x < N; x++) {
        if (mat[row][x] == num || mat[x][col] == num) return false;
    }
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (mat[startRow + i][startCol + j] == num)
                return false;
    return true;
}

bool solveSudoku(vector<vector<int>>& mat, int row = 0, int col = 0) {
    if (row == N - 1 && col == N) return true;
    if (col == N) { row++; col = 0; }

    if (mat[row][col] != 0)
        return solveSudoku(mat, row, col + 1);

    for (int num = 1; num <= N; num++) {
        if (isSafe(mat, row, col, num)) {
            mat[row][col] = num;
            if (solveSudoku(mat, row, col + 1))
                return true;
        }
    }
    mat[row][col] = 0; // backtrack
    return false;
}

int main() {
    vector<vector<int>> board = {
        {5,3,0, 0,7,0, 0,0,0},
        {6,0,0, 1,9,5, 0,0,0},
        {0,9,8, 0,0,0, 0,6,0},
        {8,0,0, 0,6,0, 0,0,3},
        {4,0,0, 8,0,3, 0,0,1},
        {7,0,0, 0,2,0, 0,0,6},
        {0,6,0, 0,0,0, 2,8,0},
        {0,0,0, 4,1,9, 0,0,5},
        {0,0,0, 0,8,0, 0,7,9}
    };

    if (solveSudoku(board)) {
        cout << "Solved Sudoku:\n";
        printBoard(board);
    } else {
        cout << "No solution exists\n";
    }
    return 0;
}

