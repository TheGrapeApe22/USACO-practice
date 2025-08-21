#include <bits/stdc++.h>
#define low first
#define high second

using namespace std;
using ll = long long;

int main() {
    constexpr ll mod = (ll)1e9+7;

    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    ll n, m;
    cin >> n >> m;

    vector<pair<ll, ll>> bounds (n, {1, m});
    for (ll i = 0; i < n; i++) {
        ll k;
        cin >> k;
        if (k != 0)
            bounds[i] = {k, k};
    }
    for (ll i = 1; i < n; i++) {
        bounds[i].low = max(bounds[i].low, bounds[i-1].low - 1);
        bounds[i].high = min(bounds[i].high, bounds[i-1].high + 1);
    }
    for (ll i = n-2; i >= 0; i--) {
        bounds[i].low = max(bounds[i].low, bounds[i+1].low - 1);
        bounds[i].high = min(bounds[i].high, bounds[i+1].high + 1);
    }
    // for (ll i = 0; i < n; i++) {
    //     cout << bounds[i].low << ", " << bounds[i].high << "\n";
    // }
    vector<vector<ll>> counts (n, vector<ll> (m+1, 0));
    ll sum = 0;
    for (ll i = 0; i < n; i++) {
        for (ll j = bounds[i].low; j <= bounds[i].high; j++) {
            if (i == 0)
                counts[i][j] = 1;
            else {
                counts[i][j] += counts[i-1][j];
                if (j-1 >= 0)
                    counts[i][j] += counts[i-1][j-1];
                if (j+1 <= m)
                    counts[i][j] += counts[i-1][j+1];
                
                counts[i][j] %= mod;
            }
            if (i == n-1) {
                sum += counts[i][j];
                sum %= mod;
            }
            // cout << i << " " << j << " " << counts[i][j] << "\n";
        }
    }
    cout << sum << "\n";
}
