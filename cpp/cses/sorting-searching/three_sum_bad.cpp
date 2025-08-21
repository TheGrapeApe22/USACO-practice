#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n, x;
    cin >> n >> x;

    vector<int> nums (n);
    unordered_map<int, int> lastIndex;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        lastIndex[nums[i]] = i;
    }

    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            const auto& it = lastIndex.find(x - nums[i] - nums[j]);
            if (it != lastIndex.end()) {
                int k = (*it).second;
                if (k != i && k != j) {
                    cout << i+1 << " " << j+1 << " " << k+1 << "\n";
                    return 0;
                }
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}
