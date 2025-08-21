/*
my solution is absolute garbage, cses solution is so simple
*/

#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define _ << " " <<
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using pii = pair<int, int>;
namespace {
    template<typename it> void print(it, it);
    template<typename T> void print(T& v) {print(all(v));}
    template<typename T, typename U> void print(pair<T, U> p) { cout << "("<<p.first<<", "<<p.second<<")"; }
    template<typename T, typename U>ostream& operator<<(ostream& out, pair<T, U> p) { print(p); return out; }
    template<typename T> ostream& operator<<(ostream& out, const vector<T>& v) { print(v); return out; }
    template<typename T> ostream& operator<<(ostream& out, const set<T>& v) { print(v); return out; }
    template<typename T> ostream& operator<<(ostream& out, const multiset<T>& v) { print(v); return out; }
    template<typename T, typename U> ostream& operator<<(ostream& out, const map<T, U>& v) { print(v); return out; }
    template<typename it> void print(it begin, it end) {
        cout << "[";
        if (begin != end) {
            auto last = --end;
            for (; begin != last; begin++)
                cout << *begin << ", ";
            cout << *last;
        }
        cout << "]";
    }
    template<typename T> void println(T v) {print(v); cout << "\n";}
}

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj (n);
    vector<vector<int>> par (n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        
        adj[a].push_back(b);
        par[b].push_back(a);
    }
    
    vec<int> complete (n);
    for (int i = 0; i < n; i++) {
        if (complete[i]) continue;
        vector<bool> vis (n);
        function<void(int)> dfs = [&](int curr) {
            if (vis[curr]) return;
            vis[curr] = true;
            for (int x : adj[curr])
                dfs(x);
        };
        dfs(i);
        for (int j = 0; j < n; j++) {
            if (!vis[j]) {
                cout << "NO\n" << i+1 << " " << j+1 << "\n";
                return 0;
            }
        }

        function<void(int)> dfs2 = [&](int curr) {
            if (complete[curr]) return;
            complete[curr] = true;
            for (int x : par[curr])
                dfs2(x);
        };
        dfs2(i);
    }
    cout << "YES\n";
}
