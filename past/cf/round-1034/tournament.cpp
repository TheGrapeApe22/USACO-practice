#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, j, k;
        cin >> n >> j >> k;

        int highest = 0;
        int valJ = 0;
        for (int a = 0; a < n; a++) {
            int b;
            cin >> b;
            if (a+1 == j)
                valJ = b;
            highest = max(highest, b);
        }

        if (k > 1) cout << "yes\n";
        else if (k == 1) {
            if (highest > valJ) cout << "no\n";
            else cout << "yes\n";
        }
    }
}
