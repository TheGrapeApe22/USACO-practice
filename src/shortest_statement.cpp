#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define _ << " " <<
#define all(x) (x).begin(), (x).end()
using namespace std; using ll = long long; using pii = pair<int, int>;
template<typename T> ostream& operator<<(ostream& out, const vector<T>& v) {
    cout << "["; for (size_t i = 0; i+1 < v.size(); i++) cout << v[i] << ", "; cout << *v.rbegin() << "]"; return out;
}

/*
two options.
let k = pos of [leftmost 11]
1. sutract each place where there are two ones, maximum: 2^k - 1
2. add until you reach 10000... where the 1 is at the [nearest left 0 in other number] to the left of [leftmost 11]
*/

int leftmost1 (int x) {
    for (int i = 31; i >= 0; i--) {
        if (x >> i & 1)
            return i;
    }
    return -1;
}

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int t; cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int x, y;
        cin >> x >> y;

        pii best = {-1e9, -1e9};
        auto test = [&](int a, int b) {
            if (abs(x - a) + abs(y - b) < abs(x - best.first) + abs(y - best.second))
                best = {a, b};
        };

        
    }
}
