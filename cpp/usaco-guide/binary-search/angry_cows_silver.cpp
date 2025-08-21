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

auto firstTrue = [](ll low, ll high, function<bool(ll)> f) {
    while (low < high) {
        ll mid = (low+high) / 2;
        if (f(mid))
            high = mid;
        else
            low = mid + 1;
    }
    return low;
};

auto lastTrue = [](ll low, ll high, function<bool(ll)> f) {
    while (low < high) {
        ll mid = (low+high+1) / 2;
        if (f(mid))
            low = mid;
        else
            high = mid - 1;
    }
    return low;
};

int main() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    // num bales, num cows
    ll n, k;
    cin >> n >> k;

    vec<ll> pos (n);
    for (ll i = 0; i < n; i++)
        cin >> pos[i];
    
    sort(all(pos));
    // cout << pos << ln;

    auto possible = [&](ll r) {
        ll i = 0;
        ll count = 0;
        while (i < n) {
            ll j = lastTrue(i, n-1, [&](ll other){
                return pos[other] <= pos[i] + 2*r;
            });
            // cout << i << " " << j << ln;
            i = j+1;
            count++;
        }
        return count <= k;
    };

    cout << firstTrue(0, (pos[n-1]-pos[0]+1)/2, possible) << ln;
}
