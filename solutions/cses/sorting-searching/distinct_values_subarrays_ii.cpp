// https://cses.fi/problemset/model/2428/
// silly mistake in implementation
#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define _ << " " <<
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    #define int long long
    cin.tie(nullptr); ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    
    vec<int> nums (n);
    for (int& x : nums) cin >> x;

    unordered_map<int, int> curr_freq;

    int ans = 0;
    for (int l = 0, r = 0; l < n; l++) {
        // while (r has room to move) AND (you have less than k elements OR the next element is already in curr_freq)
        while (r < n && ((int) curr_freq.size() < k || curr_freq.count(nums[r]) > 0)) {
            curr_freq[nums[r]]++;
            r++;
        }

        curr_freq[nums[l]]--;
        if (curr_freq[nums[l]] == 0)
            curr_freq.erase(nums[l]);

        ans += r-l;
    }
    cout << ans << ln;
}
