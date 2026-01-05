#include <bits/stdc++.h>
#define vec vector
using namespace std;
using ll = long long;
void print(vector<int>& v) {cout << "["; for (int i = 0; i < (int)v.size(); i++) cout << v[i] << " "; cout << "]\n";}
void print(vector<vector<int>>& v) {cout << "["; for (int i = 0; i < (int)v.size(); i++) print(v[i]); cout << "]\n";}
void print(int a, int b) {cout << "(" << a << ", " << b << ")\n";}

int main() {
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n;
    cin >> n;

    vec<int> prefix (n+1, 0);
    
    // first[mod] = pos
    vec<int> first (7, -1);
    vec<int> last (7, -1);

    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        k = (k + prefix[i - 1]) % 7;
        prefix[i] = k;
        
        if (first[k] == -1) first[k] = i;
        last[k] = i;
    }
    // print(prefix);
    // print(first);
    // print(last);
    
    int maxLength = 0;
    for (int i = 0; i < 7; i++) {
        if (first[i] == -1 || last[i] == -1) continue;
        maxLength = max(maxLength, last[i] - first[i]);
    }
    cout << maxLength << "\n";
}
