#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n;
    cin >> n;

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
    vector<vector<int>> board (n, vector<int> (n, -1));
    queue<vector<int>> q;
    q.push({0, 0});
    board[0][0] = 0;
    while (!q.empty()) {
        auto& curr = q.front();
        for (vector<int>& move : moves) {
            int row = curr[0] + move[0];
            int col = curr[1] + move[1];
            if (row < 0 || col < 0 || row >= n || col >= n) continue;
            if (board[row][col] != -1) continue;
            board[row][col] = board[curr[0]][curr[1]] + 1;
            q.push({row, col});
        }
        q.pop();
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }
}
