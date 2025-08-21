#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int t;
    cin >> t;

    for (int t1 = 0; t1 < t; t1++) {
        int n, k;
        string s;
        cin >> n >> k >> s;

        // cout << n << k << s << "\n";

        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') sum++;
        }

        if (k >= sum)
            cout << "alice\n";
        else if (n >= 2*k)
            cout << "bob\n";
        else
            cout << "alice\n";
    }
}
