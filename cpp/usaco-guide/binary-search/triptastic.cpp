#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;

ll firstTrue(ll low, ll high, function<bool(ll)> f) {
    while (low < high) {
        // round up
        ll mid = (low+high) / 2;
        if (f(mid))
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}

void solve () {
    ll n, m, k;
    cin >> n >> m >> k;
    vec<vec<ll>> prefix (n+1, vec<ll> (m+1, 0));
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            cin >> prefix[i][j];
        }
    }
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            prefix[i][j] += prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        }
    }
    
    // for 3x3: size = 1
    auto sum = [&](ll i, ll j, ll size) {
        i++; j++;
        ll x1 = i-size-1, y1 = j-size-1, x2 = i+size, y2 = j+size;
        x1 = max(x1, 0LL);
        y1 = max(y1, 0LL);
        x2 = min(x2, n);
        y2 = min(y2, m);
        // cout << x1 << " " << y1 << " " << x2  << " " << y2  << ln;
        return prefix[x2][y2] - prefix[x2][y1] - prefix[x1][y2] + prefix[x1][y1];
    };

    if (prefix[n][m] < k+1) {
        cout << "-1\n";
        return;
    }

    auto valid = [&](ll size) {
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                // skip empty rooms
                if (prefix[i+1][j+1] == prefix[i+1][j]) continue;
                if (sum(i, j, size) >= k+1)
                    return true;
            }
        }
        return false;
    };

    // cout << valid (2) << ln;

    // find largest size that is valid
    int ans = firstTrue(0LL, max(n, m), valid);
    cout << ans << ln;
}

int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++)
	    solve();
}
