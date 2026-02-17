// https://codeforces.com/contest/2195/problem/D
#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define _ << " " <<
#define all(x) (x).begin(), (x).end()
using namespace std; using ll = long long; using pii = pair<int, int>;
template<typename T> ostream& operator<<(ostream& out, const vector<T>& v) {
    cout << "["; for (size_t i = 0; i+1 < v.size(); i++) cout << v[i] << ", "; cout << *v.rbegin() << "]"; return out;
}
#define int ll

signed main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    int t; cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int n; cin >> n;
        vec<int> given (n);
        vec<int> solutions (n);
        for (auto& x : given) cin >> x;
        for (int i = 1; i < n-1; i++) {
            solutions[i] = (given[i-1] - 2*given[i] + given[i+1])/2;
        }
        int sumA = 0, sumB = 0;
        for (int i = 1; i < n-1; i++) {
            sumA += solutions[i] * i;
            sumB += solutions[n - i - 1] * i;
        }
        
        solutions[0] = (given[n-1] - sumB)/(n-1);
        solutions[n-1] = (given[0] - sumA)/(n-1);
        
        for (int x : solutions) cout << x << " ";
        cout << ln;
    }
}
