#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        string s;
        cin >> n >> s;

        vector<int> appeared (26, -1);
        bool broken = false;
        for (int j = 0; j < n; j++) {
            char c = s.at(j);
            int first = appeared[c - 'a'];
            if (first == -1) {
                appeared[c - 'a'] = j;
            }
            else if ((j > 0 && j < n - 1) || (first > 0 && first < n - 1)) {
                cout << "YES\n";
                broken = true;
                break;
            }
        }
        if (!broken)
            cout << "NO\n";
    }
}
