#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n;
    cin >> n;

    vector<int> nums (n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    
    sort(nums.begin(), nums.end());

    long long prevCount = 0;
    long long count = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] != nums[i - 1])
            prevCount = count;
        count += prevCount + 1;
        count %= ((long long)1e9+7);
    }

    cout << count << endl;
}
