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

struct point {
    int id, x, y, z;
};
ll sq(int x) {
    return (ll)x * x;
}
ll dist(point a, point b) {
    return sq(a.x-b.x) + sq(a.y-b.y) + sq(a.z-b.z);
}

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n = 1000, m = 1000;
    vec<point> points (n);
    int id = 0;
    for (auto& p : points) {
        p.id = id++;
        cin >> p.x >> p.y >> p.z;
    }

    vec<pair<ll, pii>> distances;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            distances.push_back({dist(points[i], points[j]), {points[i].id, points[j].id}});
        }
    }

    sort(all(distances));
    vec<vec<int>> adj (n);
    for (int i = 0; i < m; i++) {
        auto [a, b] = distances[i].second;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vec<bool> visited (n);
    function<ll (int)> dfs = [&](int x){
        if (visited[x]) return 0LL;
        visited[x] = true;
        ll sum = 1;
        for (int y : adj[x]) {
            sum += dfs(y);
        }
        return sum;
    };

    vec<ll> sizes;
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        sizes.push_back(dfs(i));
    }
    sort(all(sizes), greater<ll>());
    for (auto z : distances) {
        cout << z.first << ln;
    }
    cout << sizes[0]*sizes[1]*sizes[2] << ln;
}
