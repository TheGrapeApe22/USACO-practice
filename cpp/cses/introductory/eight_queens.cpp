#include <bits/stdc++.h>

using namespace std;

int getNumPossibilities(vector<string> board, int numQueens) {
    if (numQueens == 0) return 1;
    int total = 0;
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            if (board[row][col] != '.') continue;

            vector<string> boardCopy = board;
            boardCopy[row][col] = 'Q';

            for (int i = row - 1; i >= 0; i--)
                boardCopy[i][col] = 'x';
            for (int i = row + 1; i < 8; i++)
                boardCopy[i][col] = 'x';
            for (int j = col - 1; j >= 0; j--)
                boardCopy[row][j] = 'x';
            for (int j = col + 1; j < 8; j++)
                boardCopy[row][j] = 'x';
            for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--)
                boardCopy[i][j] = 'x';
            for (int i = row-1, j = col+1; i >= 0 && j < 8; i--, j++)
                boardCopy[i][j] = 'x';
            for (int i = row+1, j = col-1; i < 8 && j >= 0; i++, j--)
                boardCopy[i][j] = 'x';
            for (int i = row+1, j = col+1; i < 8 && j < 8; i++, j++)
                boardCopy[i][j] = 'x';
            
            total += getNumPossibilities(boardCopy, numQueens - 1);
            board[row][col] = 'd';
        }
    }
    return total;
}

int main() {
    vector<string> board(8);
    for (int i = 0; i < 8; i++) {
        cin >> board[i];
    }
    cout << getNumPossibilities(board, 8) << endl;
}
