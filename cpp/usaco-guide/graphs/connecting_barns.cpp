/*
color all groups of the graph (0=start, 1=end, 2...=remaining)

otherI=1
for (leftI : color0)
	find otherI closest to leftI
	dist = blah blah


stupid ass mistake:
    trying to make color array without traversing the graph
    i.e. edges {1, 2}, {3, 4}, {2, 3} would mark them as 2 different colors
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
    
    int t;
    cin >> t;

    for (int t1 = 0; t1 < t; t1++) {
        int n, m;
        cin >> n >> m;
        
        vec<vec<int>> adj (n);
        for (int i = 0; i < m; i++) {
            int a, b; cin >> a >> b; a--; b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int c = 0;
        vec<int> color (n, -1);
        vector<bool> vis (n);
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            function<void(int)> dfs = [&](int curr) {
                if (vis[curr]) return;
                vis[curr] = true;
                color[curr] = c;
                for (int x : adj[curr])
                    dfs(x);
            };
            dfs(i);
            c++;
        }

        vec<int> left;
        vec<int> right;
        for (int i = 0; i < n; i++) {
            if (color[i] == color[0]) left.push_back(i);
            if (color[i] == color[n-1]) right.push_back(i);
        }
        
        vec<ll> distLeft (c, 1e18);
        int leftI = 0;
        for (int x = 0; x < n; x++) {
            while (leftI+1 < left.size() && abs(left[leftI+1]-x) < abs(left[leftI]-x))
                leftI++;
            int y = left[leftI];
            // cout << x _ y _ abs(left[leftI+1]-x) _ abs(left[leftI])-x << ln;
            distLeft[color[x]] = min(distLeft[color[x]], (ll)(x-y)*(x-y));
        }

        vec<ll> distRight (c, 1e18);
        int rightI = 0;
        for (int x = 0; x < n; x++) {
            while (rightI+1 < right.size() && abs(right[rightI+1]-x) < abs(right[rightI]-x))
                rightI++;
            int y = right[rightI];
            distRight[color[x]] = min(distRight[color[x]], (ll)(x-y)*(x-y));
        }

        ll out = 1e18;
        for (int i = 0; i < c; i++)
            out = min(out, distLeft[i] + distRight[i]);
        cout << out << ln;
    }
}
