#include <bits/stdc++.h>
#define vec vector
using namespace std;
using ll = long long;
void print(vector<int>& v) {cout << "["; for (int i = 0; i < (int)v.size(); i++) cout << v[i] << " "; cout << "]\n";}
void print(vector<vector<int>>& v) {cout << "["; for (int i = 0; i < (int)v.size(); i++) print(v[i]); cout << "]\n";}
void print(int a, int b) {cout << "(" << a << ", " << b << ")\n";}

int main() {
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n;
    cin >> n;

    vec<int> nums (n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    
    vec<int> gcdPrefix (n, 1);
    vec<int> gcdSuffix (n, 1);
    
    int curr = nums[0];
    for (int i = 0; i < n; i++) {
        curr = gcd(curr, nums[i]);
        gcdPrefix[i] = curr;
    }
    curr = nums[n-1];
    for (int i = n-1; i >= 0; i--) {
        curr = gcd(curr, nums[i]);
        gcdSuffix[i] = curr;
    }
    // print(gcdPrefix);
    // print(gcdSuffix);

    int out = -1;
    for (int i = 0; i < n; i++) {
        // remove i
        int val;

        if (i == 0)
            val = gcdSuffix[i+1];
        else if (i == n-1)
            val = gcdPrefix[i-1];
        else
            val = gcd(gcdPrefix[i-1], gcdSuffix[i+1]);
        
        out = max(out, val);
    }
    cout << out << "\n";
}
