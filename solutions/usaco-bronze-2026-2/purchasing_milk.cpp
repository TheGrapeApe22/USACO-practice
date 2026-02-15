#include <bits/stdc++.h>
#define vec vector
#define ll long long
#define ln "\n"
using namespace std;

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;

    vec<ll> cost (1e5+1, 1e18);

    for (int i = 0; i < n; i++)
        cin >> cost[i];
    for (int i = 1; i < cost.size(); i++)
        cost[i] = min(cost[i], cost[i-1]*2);
    
    // for (int i = 0; i < 100; i++) cout << cost[i] << " ";
    // cout << ln;

    for (int i = 0; i < q; i++) {
        ll k; cin >> k;
        ll ans = 0; // total cost
        // for each bit in k
        for (int j = 0; j < 33; j++) {
            // count the cost of that bit
            if ((k >> j) & 1) ans += cost[j];
        }
        // compare that with cost of leftmost power of 2 >= k
        for (int j = 0; j < cost.size(); j++) {
            if ((1LL << j) >= k) {
                ans = min(ans, cost[j]);
                break;
            }
        }
        
        cout << ans << ln;
    }
}
