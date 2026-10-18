/*
https://cses.fi/problemset/task/2181

dp[mask][j] (2^n, m)
 = number of ways to fill columns from 1 to [j], with [mask] being column j
 = sum(dp[a bunch of other masks working backwards][j-1])

fill function(row, curr_mask, next_mask, next_column):
    // if next_column == n (last column so no space to fill next)
    //     check if space to place vertical block
    //     (edge case: corner)
    //     if yes, place and move down
    //     if no, bye bye
    if row == m
        add next_mask to the output list
    if curr_mask[row] is occupied
        fill(row+1)
    place blocks

cache[0][0] = 1
dp function(mask, j):
    check if cached
    if not cached but j=end, bye bye (return 0)

    fill() into array next_masks
    return sum of all dp(each next mask, j+1)
*/

/*
mistakes:
* forgot to check if available space before placing a block
* n instead of m for number of rows
* n-i instead of n-i-1
AYYY THAT'S ALL!! solved in 2 hours with a bitmask hint. LESGO
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
#define int long long
int MOD = (int)(1e9 + 7);

bool get_bit(int mask, int i, int n) {
    return (mask >> (n-i-1)) & 1;
}
int set_bit(int mask, int i, int n) {
    return mask | (1 << (n-i-1));
}

void fill(int row, int curr_mask, int next_mask, int next_column, int n, int m, vec<int>& out) {
    // check if done
    if (row >= n) {
        out.push_back(next_mask);
        return;
    }
    // check if current space occupied
    if (get_bit(curr_mask, row, n)) {
        fill(row + 1, curr_mask, next_mask, next_column, n, m, out);
        return;
    }
    // place blocks
    if (row+1 < n && !get_bit(curr_mask, row+1, n))
        fill(row + 2, curr_mask, next_mask, next_column, n, m, out); // vertical
    
    fill(row + 1, curr_mask, set_bit(next_mask, row, n), next_column, n, m, out);
}

// void print_binary(vec<int>& v) {
//     cout << '[';
//     for (int x : v) {
//         cout << bitset<8>(x);
//         cout << ", ";
//     }
//     cout << ']' << endl;
// }

int dp(int mask, int j, vec<vec<int>>& cache, int n, int m) {
    // cout << bitset<8>(mask) _ j << endl;
    if (cache[mask][j] != -1)
        return cache[mask][j];
    if (j == 0)
        return 0; // should have been cached
    vec<int> next_masks = {};
    fill(0, mask, 0, j-1, n, m, next_masks);
    // print_binary(next_masks);
    
    int sum = 0;
    for (int next_mask : next_masks) {
        sum += dp(next_mask, j-1, cache, n, m);
        sum %= MOD;
    }
    cache[mask][j] = sum;
    return sum;
}

signed main() {
    // freopen("file.in", "r", stdin); freopen("file.out", "w", stdout);
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    
    vec<vec<int>> cache ((1<<n), vec<int>(m+1, -1));
    cache[0][0] = 1;
    cout << dp(0, m, cache, n, m) << endl;

    // for (auto&z : cache) {
    //     cout << z << endl;
    // }
}
