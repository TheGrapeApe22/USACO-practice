/*
     - if dist(start + wind(t), end) <= t, you can get there in t
     - if after one cycle, you can't reach it and you're farther than you were, then -1
     - given: delta wind gets you closer.
     - finding min dist from end: O(n)
     - finding wind(t): O(1)
*/

#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

map<char, pii> dir {
    {'U', {0, 1}},
    {'D', {0, -1}},
    {'L', {-1, 0}},
    {'R', {1, 0}}
};

ll firstTrue(ll low, ll high, function<bool(ll)> f) {
    while (low < high) {
        ll mid = (low+high) / 2;
        if (f(mid))
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    string s;
    ll x1, y1, x2, y2, n;
    cin >> x1 >> y1 >> x2 >> y2 >> n >> s;

    ll wx = 0, wy = 0;
    vec<pii> wind;
    for (char c : s) {
        wind.push_back({wx, wy});
        wx += dir[c].first;
        wy += dir[c].second;
    }
    
    auto possible = [&](ll t) {
        ll cycles = t/n;
        ll remainder = t - cycles*n;
        ll nx = x1 + wx * cycles + wind[remainder].first;
        ll ny = y1 + wy * cycles + wind[remainder].second;

        return abs(nx - x2) + abs(ny - y2) <= t;
    };

    ll ans = firstTrue(0, (ll)1e18, possible);
    if (possible(ans))
        cout << ans << ln;
    else
        cout << "-1\n";    
}
