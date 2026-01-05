#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n;
    cin >> n;

    vector<vector<int>> arrays;

    auto compare = [](const int lhs, const vec<int>& rhs) {
        // descending
        return lhs > rhs[rhs.size()-1];
    };

    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        // largest that's strictly less
        auto it = upper_bound(all(arrays), k, compare);
        if (it == arrays.end())
            arrays.push_back({k});
        else
            (*it).push_back(k);
    }

    for (auto& row : arrays) {
        for (int x : row)
            cout << x << " ";
        cout << ln;
    }
}
