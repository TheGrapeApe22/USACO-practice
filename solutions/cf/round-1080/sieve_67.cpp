// https://codeforces.com/contest/2195/problem/A
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
    // freopen("file.in", "r", stdin); freopen("file.out", "w", stdout);
    cin.tie(nullptr); ios::sync_with_stdio(false);
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        int n; cin >> n;
        bool sixseven = false;
        for (int j = 0; j < n; j++) {
            int k; cin >> k;
            if (k == 67)
                sixseven = true;
        }
        cout << (sixseven ? "YES" : "NO") << ln;
    }
}
