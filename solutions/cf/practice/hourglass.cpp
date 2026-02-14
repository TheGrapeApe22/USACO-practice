// https://codeforces.com/contest/2184/problem/B
#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define _ << " " <<
#define all(x) (x).begin(), (x).end()
using namespace std; using ll = long long; using pii = pair<int, int>;
template<typename T> ostream& operator<<(ostream& out, const vector<T>& v) {
    cout << "["; for (size_t i = 0; i+1 < v.size(); i++) cout << v[i] << ", "; cout << *v.rbegin() << "]"; return out;
}

/*
time 0: s (maximum)
time k: s-k, or 0 (minimum)

m %= 2*k
if m<k:
    return max(0, s-m)
else:
    return max(0, s - (max(0, s-k) + m-k))
*/

int solve() {
    int s, k, m;
    cin >> s >> k >> m;
    m %= 2*k;
    if (m<k)
        return max(0, s-m);
    else
        return max(0, s - (max(0, s-k) + m-k));
}

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    int t; cin >> t;
    for (int i = 0; i < t; i++) cout << solve() << ln;
}
