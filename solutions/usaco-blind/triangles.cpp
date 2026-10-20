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
make the sorted array into prefix sums?. (_,a,b,c) -> (0, a, a+b, a+b+c)

for each point P
    do the thing.
    // [r] and [l] are just n-i-1 and i because iterating sparse array!
    [sum from 0 to P.x] = y_equals[y][i]
    [sum from P.x to end] = y_equals[y][num_xs] - y_equals[y][i+1]
    
    find j of x_equals[j] via binary search
    add thingy.
    
i think i got it. implement.
*/

/*
mistake: a bunch of OBOs, misvariables
mistake: put 0 in prefix sum and sorted it, but this fails for negative coordinates. had to cheat with a sample case for this one.

DOWNLAODED THE SAMPLE CASE FOR BRONZE PROBLEM INSTEAD OF SILVER AND I WAS SO FREAKING CONFUSED.
*/


#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define _ << " " <<
#define all(x) (x).begin(), (x).end()
using namespace std; using ll = long long; using pii = pair<int, int>;
# define int long long
template<typename T> ostream& operator<<(ostream& out, const vector<T>& v) {
    cout << "["; for (size_t i = 0; i+1 < v.size(); i++) cout << v[i] << ", "; cout << *v.rbegin() << "]"; return out;
}
int MOD = (int)(1e9 + 7);

signed main() {
    // freopen("triangles.in", "r", stdin); freopen("triangles.out", "w", stdout);
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n; cin >> n;
    
    map<int, vec<int>> y_equals;
    map<int, vec<int>> x_equals;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        y_equals[y].push_back(x);
        x_equals[x].push_back(y);
    }

    for (auto& p : y_equals) {
        auto& v = p.second;
        sort(all(v));
        v.insert(v.begin(), 0);
        for (int i = 1; i < v.size(); i++)
            v[i] += v[i-1];
    }
    for (auto& p : x_equals) {
        auto& v = p.second;
        sort(all(v));
        v.insert(v.begin(), 0);
        for (int i = 1; i < v.size(); i++)
            v[i] += v[i-1];
    }

    
    
    int total = 0;
    for (auto& p : y_equals) {
        auto& [y, xs] = p;
        // cout << y _ xs << endl;

        for (int i = 1; i < xs.size(); i++) {
            // P chosen
            int x = xs[i] - xs[i-1];
            // there are [r] points to the right, [l] to the left.
            // [sum of all x values to the right] - [P.x]*[r] + [P.x]*[l] - [sum of all x values to the left]
            int x_sums = (xs[xs.size() - 1] - xs[i]) - x * ((int)xs.size()-i-1) + x * (i-1) - xs[i-1];
            
            auto& ys = x_equals[xs[i] - xs[i-1]];
            
            // int j = lower_bound(all(ys), y) - ys.begin();
            
            int j = 1;
            while (ys[j] - ys[j-1] != y) j++;
            
            // cout << (ys[ys.size() - 1] - ys[j]) << endl;
            // cout << - y * ((int)ys.size()-j-1) << endl;
            // cout << y * (j-1) << endl;
            // cout << - ys[j-1] << endl;
            
            int y_sums = (ys[ys.size() - 1] - ys[j]) - y * ((int)ys.size()-j-1) + y * (j-1) - ys[j-1];
            // cout << x _ y _ x_sums _ y_sums << endl;
            total += x_sums * y_sums;
            total %= MOD;
        }
    }
    cout << total <<endl;
}
