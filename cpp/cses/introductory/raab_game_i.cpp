#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(int n, int a, int b) {
    if (a+b > n || ((a == 0 || b == 0) && a != b)) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    int ties = n - a - b;

    // a
    for (int i = 1; i <= n-ties; i++)
        cout << i << " ";
    // ties
    for (int i = n-ties+1; i <= n; i++)
        cout << i << " ";
    cout << "\n";

    // b
    for (int i = 1; i <= n-ties; i++) {
        int out = i+a;
        if (out > n-ties)
            out -= n-ties;
        cout << out << " ";
    }
    // ties
    for (int i = n-ties+1; i <= n; i++)
        cout << i << " ";
    cout << "\n";
}

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, a, b;
        cin >> n >> a >> b;

        solve(n, a, b);
    }
}
