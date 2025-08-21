#include <bits/stdc++.h>
#define vec vector
using namespace std;
using ll = long long;
void print(vector<int>& v) {cout << "["; for (int i = 0; i < (int)v.size(); i++) cout << v[i] << " "; cout << "]\n";}
void print(vector<vector<int>>& v) {cout << "["; for (int i = 0; i < (int)v.size(); i++) print(v[i]); cout << "]\n";}
void print(int a, int b) {cout << "(" << a << ", " << b << ")\n";}

int main() {
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n, k, b;
    cin >> n >> k >> b;

    vec<int> prefix (n+1, 0);
    for (int i = 0; i < b; i++) {
        int x;
        cin >> x;
        prefix[x] = 1;
    }

    for (int i = 1; i <= n; i++)
        prefix[i] += prefix[i-1];
    // print(prefix);

    int out = n;
    for (int i = 0; i <= n-k; i++) {
        out = min(out, prefix[i+k] - prefix[i]);
    }
    cout << out << "\n";
}
