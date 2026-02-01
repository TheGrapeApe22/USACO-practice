// https://codeforces.com/problemset/problem/279/B
// silly mistake in implementation
#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define _ << " " <<
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n, t;
    cin >> n >> t;

    vec<ll> times (n);
    for (ll& x : times) cin >> x;

    int max_books = 0;
    ll curr_time = 0;
    for (int l = 0, r = 0; l < n; l++) {
        while (r < n && curr_time + times[r] <= t) {
            curr_time += times[r];
            r++;
        }
        
        max_books = max(max_books, r-l);

        curr_time -= times[l];
    }
    cout << max_books << ln;
}
