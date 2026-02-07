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
    
    ll n, k, q;
    cin >> n >> k >> q;

    vec<vec<ll>> cowBeauty (n, vec<ll>(n, 0));
    vec<vec<ll>> sumBeauty (n, vec<ll>(n, 0));

    auto inBounds = [&](ll r, ll c){
        return r>=0 && c>=0 && r<n && c<n;
    };
    ll maxBeauty = 0;
    for (ll inp = 0; inp < q; inp++) {
        ll r, c, v;
        cin >> r >> c >> v;
        r--; c--;

        ll add = v - cowBeauty[r][c];

        for (ll i = max(r-k+1LL, 0LL); i<=r; i++) {
            for (ll j = max(c-k+1LL, 0LL); j<=c; j++) {
                sumBeauty[i][j] += add;
                maxBeauty = max(maxBeauty, sumBeauty[i][j]);
            }
        }

        // for (auto z : sumBeauty)
        //     cout << z << ln;

        cowBeauty[r][c] += add;

        cout << maxBeauty << ln;
    }
}
