/*
https://usaco.org/index.php?page=viewproblem2&cpid=1565

i failed to come up with a test case that my code fails at..
so i had to get a hint from chatgpt

it was:
costs: 2 3 4 8
query: 11
i would output 8+2+3=13 instead of 8+4=12.

fixed with like 3 extra lines, even though my thought process to reach this point was so convoluted and unfocused.
*/

#include <bits/stdc++.h>
#define vec vector
#define ll long long
#define ln "\n"
using namespace std;
#define int long long


int solve(int k, vec<int>& cost) {
    int total = 0;
    int out = (ll)1e18;
    // for each bit in k
    for (int j = 32; j >= 0; j--) {
        // count the cost of that bit
        if ((k >> j) & 1) {
            out = min(out, total + cost[j+1]);
            total += cost[j];
        }
    }
    return min(out, total);
}

signed main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;

    vec<int> cost (1e5+1, 1e18);

    for (int i = 0; i < n; i++)
        cin >> cost[i];
    for (int i = 1; i < cost.size(); i++)
        cost[i] = min(cost[i], cost[i-1]*2);
    for (int i = cost.size() - 1; i > 0; i--)
        cost[i-1] = min(cost[i-1], cost[i]);
    
    // for (int i = 0; i < 100; i++) cout << cost[i] << " ";
    // cout << ln;

    for (int i = 0; i < q; i++) {
        int k; cin >> k;
        
        cout << solve(k, cost) << ln;
    }
}
