#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1e9;
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
    
    ll n, q;
    cin >> n >> q;

    map<ll, ll> vals;
    vals[-1] = 0;
    for (ll i = 0; i < n; i++) {
        ll l, r, v;
        cin >> l >> r >> v;
        vals[l] += v;
        vals[r] -= v;
    }
    ll prev = 0;
    for (auto [i, val] : vals) {
        vals[i] += prev;
        prev = vals[i];
    }
    // cout << vals << ln;

    auto prefix = vals;
    ll prevI = -1;
    for (auto [i, val] : vals) {
        if (prevI != -1) {
            prefix[i] += prefix[prevI] + vals[prevI] * (i - prevI - 1);
        }
        prevI = i;
    }
    // cout << prefix << ln;

    for (ll q1 = 0; q1 < q; q1++) {
        ll l, r;
        cin >> l >> r;
        l--; r--;

        // last i <= r
        ll i2 = (*(--prefix.upper_bound(r))).first;
        // last i <= l-1
        ll i1 = (*(--prefix.upper_bound(l))).first;
        
        // cout << i1 <<" " << i2 << " ";
        ll rVal = prefix[i2] + vals[i2] * (r - i2);
        ll lVal = prefix[i1] + vals[i1] * (l - i1);

        // cout << lVal <<" "<< rVal <<" ";
        cout << rVal - lVal << ln;
    }
}
