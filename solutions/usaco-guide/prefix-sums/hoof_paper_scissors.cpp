#include <bits/stdc++.h>
#define vec vector
using namespace std;
using ll = long long;
void print(vector<int>& v) {cout << "["; for (int i = 0; i < (int)v.size(); i++) cout << v[i] << " "; cout << "]\n";}
void print(vector<vector<int>>& v) {cout << "["; for (int i = 0; i < (int)v.size(); i++) print(v[i]); cout << "]\n";}
void print(int a, int b) {cout << "(" << a << ", " << b << ")\n";}

const map<char, int> id = {{'H', 0}, {'P', 1}, {'S', 2}};

int main() {
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n;
    cin >> n;

    // v[time][HPS] = count;
    vec<vec<int>> prefix (n+1, vec<int> (3, 0));
    vec<vec<int>> suffix (n+1, vec<int> (3, 0));
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        prefix[i+1][id.at(c)] = 1;
        suffix[i][id.at(c)] = 1;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            prefix[i+1][j] += prefix[i][j];
            suffix[n-i-1][j] += suffix[n-i][j];
        }
    }

    for (int i = 0; i <= n; i++) {
        prefix[i][0] = max(prefix[i][0], max(prefix[i][1], prefix[i][2]));
        suffix[i][0] = max(suffix[i][0], max(suffix[i][1], suffix[i][2]));
    }
    // print(prefix);
    // print(suffix);
    int maxWins = 0;
    for (int i = 0; i < n; i++) {
        maxWins = max(maxWins, prefix[i][0] + suffix[i][0]);
    }
    cout << maxWins << "\n";
}
