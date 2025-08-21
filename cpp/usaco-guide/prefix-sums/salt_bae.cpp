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
    
    int n, m;
    cin >> n >> m;

    vec<int> v (n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    for (int i = 0; i < n; i++) {
        if (i > 0)
            v[i] = max(v[i], v[i-1] - m);
        if (i+1 < n)
            v[i] = max(v[i], v[i+1] - m);
    }
    for (int i = n-1; i >= 0; i--) {
        if (i > 0)
            v[i] = max(v[i], v[i-1] - m);
        if (i+1 < n)
            v[i] = max(v[i], v[i+1] - m);
    }
    for (int x : v)
        cout << x << " ";
    cout << "\n";
}
