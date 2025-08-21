#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;

    vector<string> board (n);
    for (int i = 0; i < n; i++)
        cin >> board[i];
    
    vector<string> out (n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            /* exclude:
                board[i][j]
                out[i-1][j]
                out[i][j-1]
            */
            vector<int> excluded (4);
            excluded[board[i][j] - 'A'] = 1;
            if (i-1 >= 0)
                excluded[out[i-1][j] - 'A'] = 1;
            if (j-1 >= 0)
                excluded[out[i][j-1] - 'A'] = 1;
            
            for (int k = 0; k < 4; k++) {
                if (!excluded[k]) {
                    out[i] += ('A' + k);
                    break;
                }
            }
        }
    }
    for (string& s : out)
        cout << s << "\n";
}
