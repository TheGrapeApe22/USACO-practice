#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1000, M = 1000;
int n, m;
vector<string> board (N);
vector<vector<bool>> visited (N, vector<bool> (M, false));

vector<vector<int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void dfs (int row, int col) {
    visited[row][col] = true;
    for (auto move : moves) {
        int nr = move[0] + row;
        int nc = move[1] + col;
        
        if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
        if (board[nr][nc] == '#') continue;
        if (visited[nr][nc]) continue;
        
        dfs(nr, nc);
    }
}

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    // int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
        cin >> board[i];
    
    
    int numRooms = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == '#') continue;
            if (visited[i][j]) continue;
            // cout << i << " " << j << endl;
            dfs(i, j);
            numRooms++;
        }
    }
    cout << numRooms << endl;
}
