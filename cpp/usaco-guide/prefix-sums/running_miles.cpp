#include <bits/stdc++.h>
#define vec vector
using namespace std;
using ll = long long;
void print(vector<int>& v) {cout << "["; for (int i = 0; i < (int)v.size(); i++) cout << v[i] << " "; cout << "]\n";}
void print(vector<vector<int>>& v) {cout << "["; for (int i = 0; i < (int)v.size(); i++) print(v[i]); cout << "]\n";}
void print(int a, int b) {cout << "(" << a << ", " << b << ")\n";}

void solve(vec<int> nums) {
    int n = nums.size();

    vec<int> left = nums, right = nums;
    for (int i = 0; i < n; i++) {
        left[i] += i;
        if (i > 0)
            left[i] = max(left[i], left[i-1]);

        int j = n-i-1;
        right[j] -= j;
        if (j < n-1)
            right[j] = max(right[j], right[j+1]);
    }

    int best = 0;
    for (int i = 1; i < n-1; i++) {
        best = max(best, left[i-1] + right[i+1] + nums[i]);
    }
    cout << best << "\n";
}

int main() {
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n; cin >> n;
        vec<int> nums (n);
        for (int j = 0; j < n; j++)
            cin >> nums[j];
        
        solve(nums);
    }
}
