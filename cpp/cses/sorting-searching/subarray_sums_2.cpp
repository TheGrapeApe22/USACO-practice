#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    ll n, x;
    cin >> n >> x;

    map<ll, ll> counts;
    counts[0] = 1;

    ll sum = 0;
    ll numMatches = 0;
    for (int i = 0; i < n; i++) {
        ll k;
        cin >> k;

        sum += k;
        // sum - (sum - x) = x
        numMatches += counts[sum - x];
        counts[sum]++;
    }
    cout << numMatches << "\n";
}
