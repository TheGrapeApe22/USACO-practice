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

signed main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int t; cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int n, a, b;
        cin >> n >> a >> b;
        vec<int> additions {0}, multiplications {0};
        vec<int> types (n);
        for (int i = 0; i < n; i++)
            cin >> types[i];
        for (int i = 0; i < n; i++) {
            int k; cin >> k;
            if (types[i] == 1)
                additions.push_back(k);
            else
                multiplications.push_back(k);
        }
        sort(all(additions));
        sort(all(multiplications));
        for (int i = 1; i < (int)additions.size(); i++)
            additions[i] += additions[i-1];
        for (int i = 1; i < (int)multiplications.size(); i++)
            multiplications[i] += multiplications[i-1];
        
        // cout << additions << ln;
        // cout << multiplications << ln;

        int minCost = (ll)1e18;
        // for each k (number of additions):
        for (int k = 0; k < (int)additions.size(); k++) {
            // find minimum number of multiplications necessary [O(log n)]
            int curr = a + k;
            int numMults = 0;
            while (curr < b) {
                curr *= 2;
                numMults++;
            }
            // cout << numMults << ln;
            if (numMults >= (int)multiplications.size()) {
                // break outer TODOTODOTODTODTODTIOHASDKFJHAKLSJDFHLKJH
                continue;
            }
            // count cost [O(1)]
            int cost = additions[k] + multiplications[numMults];
            // cout << k _ numMults _ cost << ln;
            minCost = min(minCost, cost);
        }
        if (minCost == (ll)1e18) minCost = -1;
        cout << minCost << ln;
    }
}
