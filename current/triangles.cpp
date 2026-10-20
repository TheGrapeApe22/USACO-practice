/*
https://usaco.org/index.php?page=viewproblem2&cpid=1015

my old solution fails to the big plus sign of points :(
i considered the worst case instead to be a big square. and i thought O(n^1.5) was a perfect fit :((

BUT THE PLUS SIGN IS BRILLIANT! WE CONTINUE SOLVING.

assume point P is a right-angle-point of a triangle.
    there are [r] points to the right, [l] to the left.
    [sum of all x values to the right] - [P.x]*[r] + [P.x]*[l] - [sum of all x values to the left]

    do the same thing for y and multiply them?
    you get total area.
    YOU GET TOTAL AREA. WHAT THE HECK.

    USE PREFIX SUMS TO AUTOMATE THE SUMMING!!!
REPEAT FOR EVERY POINT P! HELL YEAH

lower level implementation.
construct sparse arrays for (x, {y array sorted}) and (y, {x array sorted})
make the sorted array into prefix sums?. (a,b,c) -> (a,a+b,a+b+c)

for each point P
    do the thing.
    [r] and [l] are just n-i-1 and i because iterating sparse array!
    [sum from 0 to P.x] = y_to_xs[i-1]
    [sum from P.x to end] = y_to_xs[n-1] - y_to_xs[i]
    
    find x_to_ys[j] via binary search
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
    // freopen("triangles.in", "r", stdin); freopen("triangles.out", "w", stdout);
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n; cin >> n;
    
}
