#include<iostream>
#define N 10
using namespace std;
int board[N][N] = {0}, dirX[8] = {-2, -2, -1, -1, 1, 1, 2, 2}, dirY[8] = {1, -1, 2, -2, 2, -2, 1, -1};
int insideBoard(int n, int row, int col) {
    return col >= 0 && row >= 0 && col < n && row < n;
}
void printBoard(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
        cout << "\n----------\n";
}
void dfs(int n, int step, int row, int col) {
    if (step == n * n - 1) {
        printBoard(n);
        return;
    }
    for (int i = 0; i < 8; ++i) {
        int newCol = col + dirX[i], newRow = row + dirY[i];
        if (insideBoard(n, newRow, newCol) && board[newRow][newCol] == -1) {
            board[newRow][newCol] = step + 1;
            dfs(n, step + 1, newRow, newCol);
            board[newRow][newCol] = -1;
        }
    }
}
int main() {
    int n = 5;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            board[i][j] = -1;
        }
    }
    board[0][0] = 0;
    dfs(n, 0, 0, 0);
}