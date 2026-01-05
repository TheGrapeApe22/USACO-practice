#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> nums;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        nums.emplace_back(k, i+1);
    }

    sort(nums.begin(), nums.end());

    // unordered_map<int, int> lastIndex;
    // for (int i = 0; i < n; i++) {
    //     lastIndex[nums[i].first] = i;
    // }

    for (int i = 0; i < n - 2; i++) {
        int left = i+1;
        int right = n-1;

        while (left < right) {
            ll curr = (ll)nums[i].first + nums[left].first + nums[right].first;
            if (curr == x) {
                cout << nums[i].second << " " << nums[left].second << " " << nums[right].second << "\n";
                return 0;
            }
            else if (curr < x)
                left++;
            else
                right--;
        }
    }
    cout << "IMPOSSIBLE\n";
}
