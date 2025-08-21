#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;

template<typename it> void print(it, it);
template<typename T> void print(T v) {print(all(v));}
ostream& operator<<(ostream& out, const pair<const int, int>& p) { cout << "("<<p.first<<", "<<p.second<<")"; return out; }
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

int main() {
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    ll n, q;
    cin >> n >> q;

    map<ll, ll> count;

    for (ll i = 0; i < n; i++) {
        ll k;
        cin >> k;
        count[k] = 1;
    }
    count[-1] = 0;
    count[1e9+1] = (*count.crbegin()).second;

    ll prev = 0;
    for (auto [a, b] : count) {
        count[a] += prev;
        prev = count[a];
    }
    // cout << count << endl;

    for (ll i = 0; i < q; i++) {
        ll x, y;
        cin >> x >> y;

        // a < x, b <= y
        auto a = count.lower_bound(x);        
        a--;

        auto b = count.upper_bound(y);
        b--;

        cout << (*b).second - (*a).second << ln;
    }
}
