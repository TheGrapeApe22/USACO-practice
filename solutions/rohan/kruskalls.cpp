#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
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

    vec<vec<int>> edges (m, vec<int> (3));
    for (auto& edge : edges) {
        for (int j = 0; j < 3; j++)
            cin >> edge[j];
    }
    sort(all(edges));

    vec<int> p(n);
    iota(all(p), 0);

    function<int(int)> find = [&](int x) {
        if (p[x] == x) return x;
        p[x] = find(p[x]);
        return p[x];
    };
    
    for (int i = 0; i < m; i++) {
        int a = edges[i][0], b = edges[i][1], cost = edges[i][2];
        // skip if a and b are already connected
        if (find(a) == find(b)) continue;

        // merge a, b
        
        // cout << index of the edge
    }
}
