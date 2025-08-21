#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n, x;
    cin >> n >> x;

    vector<ll> coins (n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    
    vector<ll> numCombos (x+1);
    numCombos[0] = 1;
    for (int i = 1; i <= x; i++) {
        for (ll coin : coins) {
            if (i - coin >= 0) {
                numCombos[i] += numCombos[i - coin];
                numCombos[i] %= (ll)(1e9+7);
            }
        }
    }
    // cout << "["; for (auto z : numCombos) cout << z << " "; cout << "]\n";
    cout << numCombos[x] << "\n";
}
