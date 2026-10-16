#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int t; cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int n; cin >> n;
        vector<int> a (n);
        for (int& x : a) cin >> x;
        vector<int> b = a;
        for (int i = 1; i < n-1; i++) {
            if (b[i] > b[i-1] && b[i] > b[i+1]) {
                b[i] = max(b[i-1], b[i+1]);
            }
            else if (b[i] < b[i-1] && b[i] < b[i+1]) {
                b[i] = min(b[i-1], b[i+1]);
            }
        }
        for (int x : b) cout << x << " ";
        cout << " ";
    }
}
