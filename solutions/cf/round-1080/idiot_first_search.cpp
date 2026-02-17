// https://codeforces.com/contest/2195/problem/E
#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define _ << " " <<
#define all(x) (x).begin(), (x).end()
using namespace std; using ll = long long; using pii = pair<int, int>;
template<typename T> ostream& operator<<(ostream& out, const vector<T>& v) {
    cout << "["; for (size_t i = 0; i+1 < v.size(); i++) cout << v[i] << ", "; cout << *v.rbegin() << "]"; return out;
}
#define int long long

struct node {
    int x, par, left, right, value=0, sumValue=0;
};

signed main() {
    int MOD = 1e9+7;
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int t; cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int n; cin >> n;
        vec<node> nodes (n+1);
        for (int i = 1; i <= n; i++) {
            cin >> nodes[i].left >> nodes[i].right;
            nodes[nodes[i].left].par = i;
            nodes[nodes[i].right].par = i;
        }
        function<int(int)> getValue = [&](int i){
            if (nodes[i].left == 0) return 0LL;
            nodes[i].value = (getValue(nodes[i].left) + getValue(nodes[i].right) + 4) % MOD;
            return nodes[i].value;
        };
        
        function<void(int)> sumValue = [&](int i){
            if (nodes[i].left == 0) return;
            nodes[nodes[i].left].value += nodes[i].value + 1;
            nodes[nodes[i].left].value %= MOD;
            nodes[nodes[i].right].value += nodes[i].value + 1;
            nodes[nodes[i].right].value %= MOD;

            sumValue(nodes[i].left);
            sumValue(nodes[i].right);
        };

        getValue(1);
        sumValue(1);
        for (int i = 1; i <= n; i++)
            cout << (nodes[i].value+1)%MOD << " ";
        cout << ln;
    }
}
