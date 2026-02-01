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
    for (ll coin : coins) {
        for (int amt = 0; amt <= x; amt++) {
            if (amt - coin >= 0) {
                numCombos[amt] += numCombos[amt - coin];
                numCombos[amt] %= (ll)(1e9 + 7);
            }
        }
    }
    // cout << "["; for (auto z : numCombos) cout << z << " "; cout << "]\n";
    cout << numCombos[x] << "\n";
}
