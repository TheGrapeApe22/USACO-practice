// https://codeforces.com/contest/2195/problem/C
#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define _ << " " <<
#define all(x) (x).begin(), (x).end()
using namespace std; using ll = long long; using pii = pair<int, int>;
template<typename T> ostream& operator<<(ostream& out, const vector<T>& v) {
    cout << "["; for (size_t i = 0; i+1 < v.size(); i++) cout << v[i] << ", "; cout << *v.rbegin() << "]"; return out;
}

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    int t; cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int n; cin >> n;
        vec<int> rolls (n);
        for (int& x : rolls) cin >> x;
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (rolls[i] == 7 - rolls[i-1] || rolls[i] == rolls[i-1]) {
                ans++;
                i++;
            }
        }
        cout << ans << ln;
    }
}
