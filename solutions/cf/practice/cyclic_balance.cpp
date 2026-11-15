/*
https://codeforces.com/problemset/problem/2260/E
*2000

use prefix sums to track 00s, 01s, 10s, 11s
obs: 01s always = 10s
let a = 00s, b = 01s, c = 11s

set b to 0 and assume the goal is to get a and c to 0 using minimum number of these operations:
(we can ignore b now)
* a-=2, c-=1
    (equivalent to: a--, b++, (subtract 1 from everything))
* a-=1, c-=2
* a++
* c++

mistakes:
* failed to consider all negatives edge case
* had to ask AI. my solution to the abc problem IS FLAWED. fails at a=b=3

YESSSS I ADDED JUST ONE MORE LINE AND THE WHOLE THING WORKED I'M A GENIIUS YOOOOOOO
*/

#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define _ << " " <<
#define all(x) (x).begin(), (x).end()
#define int long long
using namespace std; using ll = long long; using pii = pair<int, int>; using vi = vector<int>;
template<typename T> ostream& operator<<(ostream& out, const vector<T>& v) {
    cout << "["; for (size_t i = 0; i+1 < v.size(); i++) cout << v[i] << ", "; cout << *v.rbegin() << "]"; return out;
}

int to_int(char a, char b) {
    return a-'0' + 2*(b - '0');
}

signed main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n, q;
    string s;
    cin >> n >> q >> s;
    vec<vi> prefix (4, vi(n));

    for (int i = 1; i < n; i++) {
        for (vi& row : prefix)
            row[i] += row[i-1];
        prefix[to_int(s[i-1], s[i])][i]++;
    }
    
    // for (auto& z : prefix) cout << z << ln;
    
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;

        int overflow = to_int(s[r], s[l]);

        int a = prefix[0][r] - prefix[0][l] + (overflow == 0);
        int b = prefix[1][r] - prefix[1][l] + (overflow == 1);
        int c = prefix[3][r] - prefix[3][l] + (overflow == 3);

        a -= b;
        c -= b;
        if (a < c) swap(a, c);

        if (a < 0 && c < 0) {
            cout << -(a+c) << ln;
            continue;
        }

        // cout _ a _ c << ln;

        int total = 0;
        int nc = max(c, (a+1)/2);
        total += nc - c;
        total += 2*nc - a;
        total += nc;
        total -= min((2*nc-a), nc)/3 * 4;
        cout << total << ln;
    }
}
