/*
https://usaco.org/index.php?page=viewproblem2&cpid=1448
this is an implementation problem :((( usaco bad
edit: NO THERE ARE HARDER PROBLEMS WHAT THE HECK HOW DO I DO THIS


store 2D array of [cells]

cell:
* state [L, R, U, D, empty]
* if empty: paths_to_freedom [L: true, R: true, ...]
* if not empty: final_dest (either a coordinate or 'dead')

when new conv belt added:
* if it points to dead, then it dead.
    * remove from path_to_freedom, adjacent

when cell dies:
* remove from path_to_freedom for adjacent cells
* if those cells die, do same

perhaps [cell death] can be a recursive function!
*/

#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define _ << " " <<
#define all(x) (x).begin(), (x).end()
using namespace std; using ll = long long; using pii = pair<int, int>;
template<typename T> ostream& operator<<(ostream& out, const vector<T>& v) {
    cout << "["; for (size_t i = 0; i+1 < v.size(); i++) cout << v[i] << ", "; cout << *v.rbegin() << "]"; return out;
}
// #define int long long

signed main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int t; cin >> t;
    for (int t1 = 0; t1 < t; t1++);
}
