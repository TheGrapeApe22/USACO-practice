#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ostream& operator<<(ostream& out, const vector<int>& v) {
    out << "[";
    if (v.size() > 0) {
        auto last = --v.end();
        for (auto it = v.begin(); it != last; it++)
            out << *it << ", ";
        out << *last;
    }
    out << "]";
    return out;
}

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n;
    cin >> n;

    vector<ll> numWays (n + 1, 0);
    numWays[0] = 1;
    for (int i = 0; i <= n; i++) {
        for (int roll = 1; roll <= 6; roll++) {
            if (i - roll >= 0) {
                numWays[i] += numWays[i - roll];
                numWays[i] %= ((ll)1e9 + 7);
            }
        }
    }
    // cout << numWays << endl;

    cout << numWays[n] << "\n";
}
