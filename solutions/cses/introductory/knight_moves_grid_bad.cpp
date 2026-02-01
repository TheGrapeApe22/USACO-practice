#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<vector<int>> board (n, vector<int> (n));

    vector<vector<int>> init = {
        {0, 3, 2, 3},
        {3, 4, 1, 2},
        {2, 1, 4, 3},
        {3, 2, 3, 2}
    };
    vector<vector<int>> moves = {
        {1, 2},
        {1, -2},
        {-1, 2},
        {-1, -2},
        {2, 1},
        {2, -1},
        {-2, 1},
        {-2, -1}
    };
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            board[i][j] = init[i][j];
    

    for (int i = 4; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            int minNeighbor = -1;
            for (auto& move : moves) {
                int row = move[0]+i;
                int col = move[1]+j;
                if (row >= n || row < 0 || col >= n || col < 0)
                    continue;
                int at = board[row][col];
                // cout << row << col << at << "\n";
                if (at != 0 && (minNeighbor == -1 || at < minNeighbor)) {
                    minNeighbor = at;
                }
            }
            board[i][j] = minNeighbor+1;
            board[j][i] = minNeighbor+1;
            // break;
        }
        // break;
    }
    if (n == 4) {
        board[0][3] = 5;
        board[3][0] = 5;
    }
    
    for (vector<int>& row : board) {
        for (int x : row)
            cout << x << " ";
        cout << "\n";
    }
}
