/*
find largest w that satisfies:
    there exists an integer x that satisfies all:
    
    when y = w-x
    1 <= x <= a, 1 <= q <= b
    a1*x + b1*y <= c1
    
    a1*x + b1*(w-x) <= c1
    x <= (c1-b1*w)/(a1-b1)
    >= for b1 > a1
*/

#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
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

const ll INF = (ll)2e18;

auto lastTrue = [](ll low, ll high, function<bool(ll)> f) {
    while (low < high) {
        ll mid = (low+high+1) / 2;
        if (f(mid))
            low = mid;
        else
            high = mid - 1;
    }
    if (f(low)) return low;
    return -1LL;
};

ll solve (vector<vector<ll>>& ineqs) {
    auto valid = [&](ll w) {
        ll low = 0, high = INF;
        for (auto& z : ineqs) {
            ll a = z[0], b = z[1], c = z[2];
            if (a == b) {
                if (b*w > c) return false;
                else continue;
            }
            if (a > b) {
                high = min(high, (c-b*w)/(a-b));
            }
            else {
                low = max(low, (ll)ceil((double)(c-b*w)/(a-b)));
            }
            if (low > high)
                return false;
        }
        return true;
    };
    return lastTrue(2, INF, valid);
}

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    ll t;
    cin >> t;

    for (ll i = 0; i < t; i++) {
        ll n, x, y;
        cin >> n >> x >> y;

        vec<vec<ll>> ineqs (n, vec<ll>(3));
        for (ll i = 0; i < n; i++) {
            cin >> ineqs[i][0] >> ineqs[i][1] >> ineqs[i][2];
        }
        ineqs.push_back({1, 0, x});
        ineqs.push_back({0, 1, y});
        ineqs.push_back({-1, 0, -1});
        ineqs.push_back({0, -1, -1});

        cout << x + y - solve(ineqs) << ln;
    }
}
