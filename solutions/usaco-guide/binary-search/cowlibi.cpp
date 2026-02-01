#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const int INF = 1e9;
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
    
    int g, n;
    cin >> g >> n;

    map<int, pii> grazings;

    for (int i = 0; i < g; i++) {
        ll x, y, t;
        cin >> x >> y >> t;

        grazings[t] = {x, y};
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        ll x, y, t;
        cin >> x >> y >> t;

        bool innocent = false;

        auto reachable = [](pair<ll, pair<ll, ll>> a, pair<ll, pair<ll, ll>> b){
            ll t1 = a.first, t2 = b.first, x1 = a.second.first, x2 = b.second.first, y1 = a.second.second, y2 = b.second.second;
            return (y2-y1)*(y2-y1)+(x2-x1)*(x2-x1) <= (t2-t1)*(t2-t1);
        };

        auto left = grazings.upper_bound(t);
        if (left != grazings.begin()) {
            left--;

            innocent = innocent || (!reachable(*left, {t, {x, y}}));
        }

        auto right = grazings.lower_bound(t);
        if (right != grazings.end()) {
            innocent = innocent || (!reachable({t, {x, y}}, *right));
        }
        // cout << innocent << ln;
        if (innocent) count++;
    }
    cout << count << ln;
}
