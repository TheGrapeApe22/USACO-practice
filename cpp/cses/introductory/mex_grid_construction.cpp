#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n;
    cin >> n;

    vector<bitset<200>> columns (n, bitset<200>());
    for (int i = 0; i < n; i++) {
        bitset<200> currRow;
        for (int j = 0; j < n; j++) {
            int x;
            for (x = 0; x < 200; x++) {
                if (columns[j][x] == 0 && currRow[x] == 0)
                    break;
            }
            columns[j][x] = 1;
            currRow[x] = 1;
            cout << x << " ";
        }
        cout << "\n";
    }
}
