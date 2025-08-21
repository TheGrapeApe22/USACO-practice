#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    multiset<long long> prices;
    for (int i = 0; i < n; i++) {
        long long k;
        cin >> k;
        prices.insert(k * -1);
    }
    
    for (int i = 0; i < m; i++) {
        if (prices.size() == 0) {
            cout << "-1\n";
            continue;
        }

        long long k;
        cin >> k;
        // find first price <= k
        auto it = prices.lower_bound(k * -1);

        if (it == prices.end()) {
            cout << "-1\n";
        }
        else {
            cout << *it * -1 << "\n";
            prices.erase(it);
        }
    }
}
