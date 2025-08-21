#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
namespace {
    template<typename it> void print(it, it);
    template<typename T> void print(T v) {print(all(v));}
    template<typename T, typename U>ostream& operator<<(ostream& out, const pair<const T, U>& p) { cout << "("<<p.first<<", "<<p.second<<")"; return out; }
    template<typename T> ostream& operator<<(ostream& out, const vector<T>& v) { print(v); return out; }
    template<typename T> ostream& operator<<(ostream& out, const set<T>& v) { print(v); return out; }
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
const ll INF = (ll)1e18;

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;

    vec<vec<pii>> adj (n);

    for (int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        adj[a].push_back({b, c});
    }

    vec<ll> dist (n, INF);
    vec<bool> visited (n, false);
    dist[0] = 0;

    // pair<int dist, int node>
    priority_queue<pii, vec<pii>, greater<pii>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        ll curr = pq.top().second;
        pq.pop();
        if (visited[curr]) continue;
        visited[curr] = true;

        for (auto [node, cost] : adj[curr]) {
            if (visited[node]) continue;
            
            if (dist[node] > dist[curr] + cost) {
                dist[node] = dist[curr] + cost;
                pq.push({dist[node], node});
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout << dist[i] << " ";
    cout << ln;
}
