#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define _ << " " <<
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
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
    
    ll n, m;
    cin >> n >> m;

    vec<bool> defined (n+1, false);
    vec<bool> vis (n+1, false);
    vec<ll> val (n+1, 0);
    vec<vec<pii>> adj (n+1);
    for (ll i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, -c});
    }

    // cout << adj << ln;

    function<bool(ll)> process = [&](ll i) {
        if (vis[i]) return true;
        vis[i] = true;
        defined[i] = true;
        
        // cout << i _ val << ln;
        while (adj[i].size()) {
            ll x = adj[i].back().first;
            ll nx = adj[i].back().second + val[i];
            adj[i].pop_back();
            if (defined[x]) {
                if (val[x] != nx) return false;
            }
            val[x] = nx;
            defined[x] = true;
            // cout << x << ln;
            if (!process(x)) return false;
        }
        return true;
    };
    for (ll i = 0; i <= n; i++) {
        // if (defined[i]) continue;
        if (!process(i)) {
            cout << "NO\n";
            return 0;
        }
    }
    // cout << val << ln;
    cout << "YES\n";
    for (ll i = 1; i <= n; i++) {
        cout << val[i]-val[i-1] << " ";
    }
    cout << ln;

    // for each i...n
        // if i isn't defined, process (i, 0)

    // process(i):
        // for each x connected to i:
            // nx = (value of connection) - val[i]
            // delete connection
            // if x is defined 
                // if val[x] != nx, "NO"
                // else return okay
            // val[x] = nx
            // process x
}
