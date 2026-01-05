#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int t;
    cin >> t;

    for (int t1 = 0; t1 < t; t1++) {
        int n;
        cin >> n;
        vector<vector<int>> v (2, vector<int> (n));
        for (int i = 0; i < n; i++)
            cin >> v[0][i];
        for (int i = 0; i < n; i++)
            cin >> v[1][i];
        
        // pos[value] = {row, col}
        map<int, pair<int, int>> pos;
        bool broken = false;
        for (int x = n-1; x >= 0; x--) {
            for (int y = 0; y <= 1; y++) {
                // search for duplicates
                int val = v[y][x];
                auto duplicate = pos.find(val);
                if (duplicate == pos.end())
                    // add position to map
                    pos[val] = {y, x};
                else {
                    // found duplicate
                    pair<int, int> other = (*duplicate).second;
                    // cout << x << ", " << y << " ... " << (other.second - y + other.first - x) << "\n";
                    if (abs(other.second - y + other.first - x) % 2 == 1 || other.second - x >= 2) {
                        cout << x+1 << "\n";
                        broken = true;
                        break;
                    }
                }
            }
            if (broken) break;
        }
        if (!broken)
            cout << 0 << "\n";
    }
}
