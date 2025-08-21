/*
find the largest x such that:
    there exists a subarray such that:
        count(< x) < count(>= x)
        -> count(>= x) - count(< x) > 0
        -> sum translated(a...b) > 0
        -> prefix(b) - prefix(a-1) = 0
        find max subarray sum of prefix of at least length k
            for each i:
                max suffix(i+k ... end) - min prefix(0...i)
*/

#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n, k;
    cin >> n >> k;

    vec<int> nums (n);
    for (int& x : nums)
        cin >> x;
    
    auto possible = [&](int median) {
        // translate + construct prefix
        vec<int> prefix (n+1);
        for (int i = 1; i <= n; i++)
            prefix[i] = prefix[i-1] + ((nums[i-1] >= median) ? 1 : -1);
        
        // check if any subarray of prefix sums to >0
        
        // construct suffix max
        vec<int> suffixMax (n+1);
        suffixMax[n] = prefix[n];
        for (int i = n-1; i >= 0; i--)
            suffixMax[i] = max(prefix[i], suffixMax[i+1]);

        // check if any subarray sum > 0
        int prefixMin = 1e9;
        for (int i = 0; i+k <= n; i++) {
            prefixMin = min(prefixMin, prefix[i]);
            if (suffixMax[i+k] - prefixMin > 0)
                return true;
        }
        return false;
    };

    auto lastTrue = [](int low, int high, function<bool(int)> f) {
        while (low < high) {
            int mid = (low+high+1) / 2;
            if (f(mid))
                low = mid;
            else
                high = mid - 1;
        }
        if (f(low)) return low;
        return -1;
    };

    cout << lastTrue(1, n, possible) << ln;
}
