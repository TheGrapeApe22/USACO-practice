#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
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

auto firstTrue = [](ll low, ll high, function<bool(ll)> f) {
    while (low < high) {
        ll mid = (low+high) / 2;
        if (f(mid))
            high = mid;
        else
            low = mid + 1;
    }
    if (f(low)) return low;
    return (ll)-1;
};

auto lastTrue = [](ll low, ll high, function<bool(ll)> f) {
    while (low < high) {
        ll mid = low + (high-low+1) / 2;
        if (f(mid))
            low = mid;
        else
            high = mid - 1;
    }
    if (f(low)) return low;
    return (ll)-1;
};


int main() {
    // freopen("socdist.in", "r", stdin);
    // freopen("socdist.out", "w", stdout);
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    ll n, m;
    cin >> n >> m;

    vec<pii> grass (m);
    for (ll i = 0; i < n; i++)
        cin >> grass[i].first >> grass[i].second;
    
    sort(all(grass));

    auto valid = [&](ll d) {
        ll curr = grass[0].first;
        ll i = 0;
        for (ll count = 1; count < n; count++) {
            curr += d;
            while (grass[i].second < curr) {
                i++;
                if (i == m) return false;
            }
            curr = max(curr, grass[i].first);
            // cout << curr << " ";
        }
        return true;
    };

    cout << lastTrue(1, (ll)1e18, valid) << ln;
}
