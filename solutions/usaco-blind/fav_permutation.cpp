/*
https://usaco.org/index.php?page=viewproblem2&cpid=1421

key observation: in non-edge cases, the two digits missing in nohj are the first and last of the original permutation.

if last digit is 1 and no repeats: first = 1, last = unmentioned digit
otherwise first, last = two unmodified digits

construct with 2 pointers
*/

#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define _ << " " <<
#define all(x) (x).begin(), (x).end()
// #define int long long
using namespace std; using ll = long long; using pii = pair<int, int>;
template<typename T> ostream& operator<<(ostream& out, const vector<T>& v) {
    cout << "["; for (size_t i = 0; i+1 < v.size(); i++) cout << v[i] << ", "; cout << *v.rbegin() << "]"; return out;
}

signed main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int t; cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        if (false) {
            abort:
            cout << -1 << ln;
            continue;
        }
        
        int n; cin >> n;
        vec<int> nohj (n-1);
        vec<bool> included(n, false);
        for (int& x : nohj) {
            cin >> x;
            included[x-1] = true;
        }
        vec<int> excluded;
        for (int i = 0; i < n; i++) {
            if (!included[i])
                excluded.push_back(i+1);
        }

        // solve
        if (excluded.size() > 2) goto abort;
        
        vec<bool> used(n+1, false);
        vec<int> out (n, -1);
        
        auto set_out = [&](int i, int x){
            // cout << out _ i _ x << endl;
            if (out[i] == x) return true;
            if (used[x]) return false;
            used[x] = true;
            out[i] = x;
            return true;
        };

        // find first and last element of permutation
        if (excluded.size() == 1) {
            if (nohj[n-2] == 1) {
                if (!set_out(0, 1)) goto abort;
                if (!set_out(n-1, excluded[0])) goto abort;
            }
            else goto abort;
        }
        else {
            if (!set_out(0, min(excluded[0], excluded[1]))) goto abort;
            if (!set_out(n-1, max(excluded[0], excluded[1]))) goto abort;
        }
        
        // iterate
        int l = 0, r = n-1;
        for (int x : nohj) {
            // cout << x _ l _ r _ out << endl;
            if (out[l] > out[r]) {
                l++;
                if (!set_out(l, x)) goto abort;
            }
            else {
                r--;
                if (!set_out(r, x)) goto abort;
            }
        }

        for (int i = 0; i < n-1; i++)
            cout << out[i] << " ";
        cout << out[n-1];
        cout << ln;
    }
}
