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
    // freopen("fenceplan.in", "r", stdin);
    // freopen("fenceplan.out", "w", stdout);
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;

    vec<vec<int>> cows (n, vec<int>(2));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++)
            cin >> cows[i][j];
    }

    vec<vec<int>> adj (n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // cout << adj << ln;

    vector<bool> vis (n);
    int out = 1e9;
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        int minX=cows[i][0], maxX=cows[i][0], minY=cows[i][1], maxY=cows[i][1];
        function<void(int)> dfs = [&](int curr) {
            if (vis[curr]) return;
            vis[curr] = true;
            minX = min(minX, cows[curr][0]);
            maxX = max(maxX, cows[curr][0]);
            minY = min(minY, cows[curr][1]);
            maxY = max(maxY, cows[curr][1]);
            for (int x : adj[curr])
                dfs(x);
        };
        dfs(i);
        // cout << maxX _ minX _ maxY _ minY << ln;
        out = min(out, 2*(maxX-minX + maxY-minY));
    }
    cout << out << ln;
}
