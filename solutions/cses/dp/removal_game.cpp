/*
https://cses.fi/problemset/result/19096666/
MISTAKES:
* silly mistake: returned 0 instead of arr[val] in edge case
* TERRIBLE DISGUSTING HORRIFYING MISTAKE (python bad): initialized cache as [[placeholder] * n] * n, which makes modifying one row modify all rows!!! TOOK SO LONG TO DEBUG ASLKJDHAASDF
* stack overflow because max recursion depth is 1000 but n can be 5000
* OBO. 5001 instead of 5000
* switched to c++ because python doesn't get TLE handicap :(
* added #define int long long
* changed main return value to signed instead of int


import sys
sys.setrecursionlimit(5001)

n = int(input())
arr = [int(x) for x in input().split()]
n = len(arr)

placeholder = -1e11
cache = [[placeholder] * n for _ in range(n)]

# print(arr)
def solve(left, right, sum):
    # print(cache)
    # print(left, right)
    if left == right:
        # print(left, right, arr[left])
        return arr[left]
    if cache[left][right] != placeholder:
        # print(left, right, cache[left][right], '(cached)')
        return cache[left][right]
    cache[left][right] = max(
        sum - solve(left+1, right, sum-arr[left]),
        sum - solve(left, right-1, sum-arr[right])
    )
    # print(left, right, cache[left][right])
    return cache[left][right]

print(solve(0, n-1, sum(arr)))
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

int PLACEHOLDER = INT_MIN;

int solve(int left, int right, int sum, vec<vec<int>>& cache, vec<int>& arr) {
    if (left == right)
        return arr[left];
    if (cache[left][right] != PLACEHOLDER)
        return cache[left][right];
    
    cache[left][right] = max(
        sum - solve(left+1, right, sum-arr[left], cache, arr),
        sum - solve(left, right-1, sum-arr[right], cache, arr)
    );
    return cache[left][right];
}

signed main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);    
    
    int n; cin >> n;
    vec<int> arr (n);
    int sum = 0;
    for (int& x : arr) {
        cin >> x;
        sum += x;
    }
    
    vec<vec<int>> cache (n, vec<int>(n, PLACEHOLDER));
    cout << solve(0, n-1, sum, cache, arr) << endl;
}
