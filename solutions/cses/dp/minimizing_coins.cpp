#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n, sum;
    cin >> n >> sum;

    vector<int> coins (n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    
    vector<int> minCoins (sum+1);
    minCoins[0] = 0;
    for (int i = 1; i <= sum; i++) {
        minCoins[i] = 1e6 + 1;
        for (int coin : coins) {
            if (i - coin >= 0 && minCoins[i - coin] != -1) {
                minCoins[i] = min(minCoins[i], minCoins[i - coin] + 1);
            }
        }
        if (minCoins[i] == 1e6 + 1)
            minCoins[i] = -1;
    }
    // cout << "["; for (auto x : minCoins) cout << x << " "; cout << "]\n";
    cout << minCoins[sum] << "\n";
}
