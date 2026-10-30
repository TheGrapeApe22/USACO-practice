/*
https://usaco.org/index.php?page=viewproblem2&cpid=1471

CSES stick lengths edit is goated for giving me the easy version of this problem

first brilliant obs: just take everything % k
do CSES stick lengths except in a circle (mod k)
try every element as "median" (m)

HOLY SHIT THIS WORKED ON FIRST SUBMIT!!!
AFTER AN HOUR OF:
* off by one errors
* negative instead of positive
* missed edge cases

looked at solution:
* ayyy chongtian has the same solution/logic, but just neat-looking illegible ternary statements :D
* WHAT THE HECK?? THERE WAS A 10 LINE PYTHON SOLUTION :skull: i am horrifiedly amazed. analyzing it rn.
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

signed main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vi v (n);
        for (int& x : v) {
            cin >> x;
            x %= k;
        }
        sort(all(v));

        vi prefix (n);
        prefix[0] = v[0];
        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i-1] + v[i];
        
        // cout << v << ln;
        // cout << prefix << ln;
        // cout << endl;
        
        int min_ops = 1e18;

        for (int m = 0; m < n; m++) {            
            auto sum_diffs = [&](int a, int b) {
                // sum the differences between v and m (median). always positive.
                int l = (a > 0) ? prefix[a-1] : 0;
                return abs(prefix[b] - l - v[m] * (b - a + 1));
            };

            if (v[m] <= k/2) {
                // i = first such that v[i] - v[m] > k/2
                int i = upper_bound(all(v), v[m] + k/2) - v.begin();
                int ops;
                if (i == n) {
                    ops = sum_diffs(0, m) + sum_diffs(m+1, n-1);
                }
                else {
                    // diff (0...m), (m+1...i-1), (i..end)
                    ops = sum_diffs(0, m) \
                        + sum_diffs(m+1, i-1) \
                        + k*(n-i) - (sum_diffs(i, n-1));
                }
                min_ops = min(min_ops, ops);
            }
            else {
                // i = last such that v[m] - v[i] > k/2
                int i = upper_bound(v.rbegin(), v.rend(), v[m] - k/2, greater<int>()) - v.rbegin();
                // cpp is goated for supporting this
                
                int ops;
                if (i == n) {
                    ops = sum_diffs(0, m) + sum_diffs(m+1, n-1);
                }
                else {
                    i = n-i-1;
                    // diff (0...i), (i+1...m), (m+1...n-1)
                    ops = k*(i+1) - sum_diffs(0, i) \
                        + sum_diffs(i+1, m) \
                        + sum_diffs(m+1, n-1);
                }
                
                min_ops = min(min_ops, ops);
            }
        }
        cout << min_ops << ln;
    }
}
