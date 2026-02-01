#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);

    // get input
    int n;
    cin >> n;
    vector<string> board (n);
    for (int i = 0; i < n; i++)
        cin >> board[i];
    
    if (board[0][0] == '*' || board[n-1][n-1] == '*') {
        cout << "0\n";
        return 0;
    }

    vector<vector<ll>> numPaths (n, vector<ll> (n));
    numPaths[0][0] = 1;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (board[y][x] == '*') continue;

            if (y-1 >= 0)
                numPaths[y][x] += numPaths[y-1][x];
            if (x-1 >= 0)
                numPaths[y][x] += numPaths[y][x-1];
            
            numPaths[y][x] %= (ll)1e9 + 7;
        }
    }
    cout << numPaths[n-1][n-1] << "\n";
}
