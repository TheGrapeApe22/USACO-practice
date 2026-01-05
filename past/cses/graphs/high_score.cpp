#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll INF = 1e18;
namespace {
    template<typename it> void print(it, it);
    template<typename T> void print(T& v) {print(all(v));}
    template<typename T, typename U> void print(pair<T, U> p) { cout << "("<<p.first<<", "<<p.second<<")"; }
    template<typename T, typename U>ostream& operator<<(ostream& out, pair<T, U> p) { print(p); return out; }
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

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;

    vec<vec<pii>> adj (n);
    vec<vec<int>> reversePath (n);

    for (int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;

        adj[a].push_back({b, c});
        reversePath[b].push_back(a);
    }

    vec<bool> visited (n);
    queue<int> q;
    q.push(n-1);
    visited[n-1] = true;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int x : reversePath[curr]) {
            if (visited[x]) continue;
            visited[x] = true;
            q.push(x);
        }
    }

    vec<bool> visited2 (n);
    q.push(0);
    visited2[0] = true;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (auto [x, c] : adj[curr]) {
            if (visited2[x]) continue;
            visited2[x] = true;
            q.push(x);
        }
    }
    // cout << visited << ln;

    vec<ll> maxScore (n, -INF);
    maxScore[0] = 0;

    bool updated = true;
    for (int i = 0; i < n && updated; i++) {
        updated = false;
        for (int curr = 0; curr < n; curr++) {
            for (auto [node, weight] : adj[curr]) {
                if (maxScore[node] < maxScore[curr] + weight) {
                    maxScore[node] = maxScore[curr] + weight;
                    updated = true;

                    if (i == n-1 && visited[curr] && visited2[curr]) {
                        cout << "-1\n";
                        return 0;
                    }
                }
            }
        }
        // cout << maxScore << ln;
    }
    cout << maxScore[n-1] << ln;
}
