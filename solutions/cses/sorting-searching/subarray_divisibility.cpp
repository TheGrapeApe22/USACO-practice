#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    ll n;
    cin >> n;

    // sparse array
    vector<ll> remainderCounts (n);
    remainderCounts[0] = 1;
    ll count = 0;
    ll sum = 0;
    for (ll i = 0; i < n; i++) {
        ll k;
        cin >> k;
        sum += k;
        sum %= n;
        if (sum < 0) sum += n;

        count += remainderCounts[sum];
        remainderCounts[sum]++;
    }
    cout << count << "\n";
}
