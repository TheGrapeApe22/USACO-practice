#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n, x;
    cin >> n >> x;

    vector<int> nums (n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    
    int count = 0;
    int left = 0, right = 0;
    int currSum = nums[0];
    if (currSum == x) count++;
    while (true) {
        if (currSum < x || left == right) {
            right++;
            if (right >= n) break;
            currSum += nums[right];
        }
        else {
            currSum -= nums[left];
            left++;
        }
        if (currSum == x) count++;
    }

    cout << count << "\n";
}
