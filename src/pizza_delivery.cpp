// https://codeforces.com/problemset/problem/2193/F
// mistakes: completely wrong implementation. confused between multiple variables. very bad screwups.
#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define _ << " " <<
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
#define int ll
using pii = pair<int, int>;
#define F first
#define S second

/*
for each column, store top and bottom, and minimum distance to each

track maps `top` and `bottom`
track min_dist_top and min_dist_bottom
track pointers prev_top and prev_bottom
iterate through with curr_top and curr_bottom:
    min_dist_top => minimize(dist(curr_top, prev_top))
    etc. for all four pairs
*/

int dist(pii a, pii b) {
    return abs(a.F - b.F) + abs(a.S - b.S);
}

void solve() {
    int n;
    cin >> n;

    vec<pii> inputs (n+2);
    for (int i = 0; i < 2; i++)
        cin >> inputs[i].F >> inputs[i].S;
    for (int i = 0; i < n; i++)
        cin >> inputs[i + 2].F;
    for (int i = 0; i < n; i++)
        cin >> inputs[i + 2].S;
    
    map<int, int> top, bottom;
    for (pii p : inputs) {
        top[p.F] = max(top[p.F], p.S);
        bottom[p.F] = min(bottom[p.F], p.S);
        if (bottom[p.F] == 0)
            bottom[p.F] = p.S;
    }

    int mindist_top = 0, mindist_bottom = 0;
    pii prev_top = *top.begin(), prev_bottom = *bottom.begin();
    auto curr_top = ++top.begin(), curr_bottom = ++bottom.begin();
    for (; curr_top != top.end(); ++curr_top, ++curr_bottom) {
        int dist_between = (*curr_top).S - (*curr_bottom).S;
        int mindist_top2 = min(mindist_top + dist(prev_top, *curr_bottom), mindist_bottom + dist(prev_bottom, *curr_bottom)) + dist_between;
        int mindist_bottom2 = min(mindist_top + dist(prev_top, *curr_top), mindist_bottom + dist(prev_bottom, *curr_top)) + dist_between;
        mindist_top = mindist_top2;
        mindist_bottom = mindist_bottom2;
        // update prevs
        prev_top = *curr_top;
        prev_bottom = *curr_bottom;
    }
    cout << min(mindist_bottom, mindist_top) << ln;
}

signed main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}
