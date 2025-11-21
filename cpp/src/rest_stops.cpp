/*
until reached end:
	find tastiest value to the right
	eat it until farmer john catches up
*/

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
    freopen("reststops.in", "r", stdin);
    freopen("reststops.out", "w", stdout);
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    ll l, n, rf, rb;
    cin >> l >> n >> rf >> rb;

    priority_queue<pii> grass;
    for (ll i = 0; i < n; i++) {
        ll x, c; cin >> x >> c;
        grass.push({c, x});
    }

    ll taste = 0;
    ll x = 0;
    ll t = 0;
    while (x < l) {
        while (!grass.empty() && grass.top().second <= x) grass.pop();
        if (grass.empty()) break;

        auto [taste1, x1] = grass.top(); grass.pop();
        ll t1 = t + (x1 - x) * rb;
        ll t2 = t + (x1 - x) * rf;
        taste += taste1 * (t2 - t1);
        x = x1;
        t = t1;
    }
    cout << taste << ln;
}
