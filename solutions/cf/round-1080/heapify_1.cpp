// https://codeforces.com/contest/2195/problem/B
#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define _ << " " <<
#define all(x) (x).begin(), (x).end()
using namespace std; using ll = long long; using pii = pair<int, int>;
template<typename T> ostream& operator<<(ostream& out, const vector<T>& v) {
    cout << "["; for (size_t i = 0; i+1 < v.size(); i++) cout << v[i] << ", "; cout << *v.rbegin() << "]"; return out;
}

int reduce (int x) {
    while (x%2 == 0) x /= 2;
    return x;
}

bool solve(vec<int>& v, int n) {
    for (int i = 1; i <= n; i++) {
        // i has to be equal to reduce(v[i]) * (some power of 2)
        if (reduce(i) != reduce(v[i-1]))
            return false;
    }
    return true;
}

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int t; cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int n; cin >> n;
        vec<int> v (n);
        for (int& x : v) cin >> x;
        cout << (solve(v, n) ? "YES" : "NO") << ln;
    }
}
