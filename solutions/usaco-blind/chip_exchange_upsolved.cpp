/*
https://usaco.org/index.php?page=viewproblem2&cpid=1539

yoooo i did this so cleanly. proud. all comments are post-passing.
*/

#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define _ << " " <<
#define all(x) (x).begin(), (x).end()
#define int long long
using namespace std; using ll = long long; using pii = pair<int, int>;
template<typename T> ostream& operator<<(ostream& out, const vector<T>& v) {
    cout << "["; for (size_t i = 0; i+1 < v.size(); i++) cout << v[i] << ", "; cout << *v.rbegin() << "]"; return out;
}

int solve(int a, int b, int cA, int cB, int fA) {
    // spend everything you alr have to lower fA
    int num_exchanges = b / cB;
    a += cA * num_exchanges;
    b -= cB * num_exchanges;
    fA -= a;
    a = 0;
    if (fA <= 0) return 0;

    //                      pour most into Bs and edge with As,      pour most into As and edge Bs
    //                       As             Bs (ceil division)
    if (cA < cB) return max((fA - 1) % cA + ((fA+cA-1)/cA) * cB - b, fA + cB - b - 1);
    // pour most into As and edge Bs
    return fA + cB - b - 1;
}

signed main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int t; cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int a, b, cA, cB, fA;
        cin >> a >> b >> cA >> cB >> fA;
        cout << solve(a, b, cA, cB, fA) << ln;
    }

}
