/*
https://codeforces.com/problemset/problem/2266/F
*2000

AYYY my first 2000 and THIS BASICALLY WORKED FIRST TRY LET'S FREAKING GOOOOO

bsearch + work backwards. to check if works:
maintain debt thingy and iterate left to right
EXAMPLE: check if 5 works.
number 5 4 3 2 1 0
count  0 0 1 3 1 5
debt     1 2 3 3 5
at each step, add (debt - count) to debt. the remaining goes to extra 0s.

optimize large gaps by multiplying by 2^(a-b-1) instead of adding (a-b) times.

mistakes:
* integer overflow
* bad limit for integer overflow
*/

#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define _ << " " <<
#define all(x) (x).begin(), (x).end()
#define int long long
using namespace std; using ll = long long; using pii = pair<int, int>; using vi = vector<int>;
template<typename T, typename U> ostream& operator<<(ostream& out, pair<T, U> p) {
    cout << "(" << p.first << ", " << p.second << ")"; return out;
}
template<typename T> ostream& operator<<(ostream& out, const vector<T>& v) {
    cout << "["; for (size_t i = 0; i+1 < v.size(); i++) cout << v[i] << ", "; cout << *v.rbegin() << "]"; return out;
}
#define val first
#define count second

int lastTrue(int low, int high, function<bool(int)> f) {
    while (low < high) {
        int mid = (low+high+1)/2;
        if (f(mid))
            low = mid;
        else
            high = mid-1;
    }
    if (f(low))
        return low;
    return -1;
}

bool DEBUG = true;

signed main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vec<pii> stock (n);
        for (pii& p : stock)
            cin >> p.val >> p.count;
        sort(stock.rbegin(), stock.rend());
        if (stock[n-1].val != 0) {
            stock.push_back({0, 0});
            n++;
        }

        auto possible = [&](int x) {
            if (x == stock[0].val) return true;
            
            int debt = 1, extras = 0;
            for (int i = 0; i < n; i++) {
                int prev_val = (i == 0) ? x : stock[i-1].val;
                auto [curr_val, curr_stock] = stock[i];
                for (int j = 0; j < prev_val - curr_val - 1; j++) {
                    debt *= 2;
                    if (debt > (int)1e17) return false;
                }
            
                if (i != n-1) {
                    debt += max(0LL, debt - curr_stock);
                    if (debt > (int)1e17) return false;
                    extras += max(0LL, curr_stock - debt);
                }
                
                // cout << curr_val _ debt << ln;
            }
            // cout << debt _ stock[n-1].count+extras << ln;
            return stock[n-1].count + extras >= debt;
        };

        // cout << stock << ln;
        // possible(7);
        
        // bin search
        cout << lastTrue(stock[0].val, (int)1e14, possible) << ln;
    }
}
