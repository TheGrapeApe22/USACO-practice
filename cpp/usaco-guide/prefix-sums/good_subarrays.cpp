/*
    for prefix sum:
    v[j] - v[i] = j - i
    (v[j] - j) = (v[i] - i)

    subtract i from every v[i], every pair of duplicates satisfies (v[j] - j) = (v[i] - i)
*/

#include <bits/stdc++.h>
#define vec vector
using namespace std;
using ll = long long;
void print(vector<int>& v) {cout << "["; for (int i = 0; i < (int)v.size(); i++) cout << v[i] << " "; cout << "]\n";}
void print(vector<vector<int>>& v) {cout << "["; for (int i = 0; i < (int)v.size(); i++) print(v[i]); cout << "]\n";}
void print(int a, int b) {cout << "(" << a << ", " << b << ")\n";}

ll solve (vec<ll> nums) {
    int n = nums.size()-1;
    for (int i = 1; i <= n; i++) {
        nums[i] += nums[i-1] - 1;
    }
    
    map<ll, int> count;
    for (ll x : nums)
        count[x]++;
    
    ll total = 0;
    for (auto [a, b] : count) {
        total += (ll)b*(b-1)/2;
    }

    return total;
}

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        string s;
        cin >> n >> s;
        
        vec<ll> nums;
        nums.push_back(0);
        for (int i = 0; i < n; i++)
            nums.push_back(s[i] - '0');
        
        cout << solve(nums) << "\n";
    }
}
