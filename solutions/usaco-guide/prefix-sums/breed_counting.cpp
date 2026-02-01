#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void print(vector<int>& v) {cout << "["; for (int i = 0; i < (int)v.size(); i++) cout << v[i] << " "; cout << "]\n";}
void print(vector<vector<int>>& v) {cout << "["; for (int i = 0; i < (int)v.size(); i++) print(v[i]); cout << "]\n";}
void print(int a, int b) {cout << "(" << a << ", " << b << ")\n";}

int main() {
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n, q;
    cin >> n >> q;

    // cows[position][id=0,1,2] = count
    vector<vector<int>> cows (n+1, vector<int> (3, 0));

    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        cows[i][k-1]++;
        
        // prefix sum
        for (int j = 0; j < 3; j++) {
            cows[i][j] += cows[i-1][j];
        }
    }
    
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        
        for (int j = 0; j < 3; j++) {
            cout << cows[b][j] - cows[a-1][j];
            if (j != 2) cout << " ";
        }
        
        cout << "\n";
    }
}
