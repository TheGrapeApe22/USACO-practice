#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll m = (ll) 1e9 + 7;

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    ll n;
    cin >> n;

    vector<ll> a (1e6);
    vector<ll> b (1e6);

    a[0] = 1;
    b[0] = 1;
    for (ll i = 1; i < 1e6; i++) {
        a[i] = (2 * a[i-1] + b[i-1]) % m;
        b[i] = (a[i-1] + 4 * b[i-1]) % m;
    }
    
    for (ll i = 0; i < n; i++) {
        ll k;
        cin >> k;
        k--;
        cout << (a[k] + b[k])%m << "\n";
    }
}
