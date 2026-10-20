// https://usaco.org/index.php?page=viewproblem2&cpid=1349
// MISSED ONE TEST CASE UGHHH

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

/*
sort plants by t
for each plant (in order of t):
    find min start and min end times when plants[i] > plants[i+1]
    if no time possible: return false
return true
*/

/*
time when plants[i] > plants[j]:
first time after major change = floor (h[j]-h[i])/(a[i]-a[j]) + 1
last time before change = ceil (h[j]-h[i])/(a[i]-a[j]) - 1
edge case a[i] == a[j]
if h[i] > h[j] return {0, last time before change}
else return {first time after major change, infinity}
*/


struct plant {
    ll h;
    ll a;
    ll t;
    bool operator< (plant& other) {
        return this->t < other.t;
    }
};

ll solve (vec<plant>& plants, ll n) {
    ll minTime = 0;
    ll maxTime = 1e18;
    for (ll i = 0; i < n-1; i++) {
        plant& p1 = plants[i];
        plant& p2 = plants[i+1];
        if (p1.a == p2.a) {
            if (p1.h == p2.h)
                return -1;
            if (p1.h > p2.h)
                continue;
            return -1;
        }
        ll afterChange = (p2.h - p1.h)/(p1.a - p2.a) + 1;
        ll beforeChange = (p2.h - p1.h + (p1.a - p2.a)-1)/(p1.a - p2.a) - 1;
        if (p1.h > p2.h) {
            if (beforeChange >= 0)
                maxTime = min(maxTime, beforeChange);
        }
        else {
            if (afterChange <= 0)
                return -1;
            minTime = max(minTime, afterChange);
        }
        // cout << minTime _ maxTime << ln;
    }
    if (minTime > maxTime) return -1;
    return minTime;
}

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    ll t; cin >> t;
    for (ll i = 0; i < t; i++) {
        ll n; cin >> n;
        vec<plant> plants (n);
        for (ll j = 0; j < n; j++) cin >> plants[j].h;
        for (ll j = 0; j < n; j++) cin >> plants[j].a;
        for (ll j = 0; j < n; j++) cin >> plants[j].t;

        sort(all(plants));
        cout << solve(plants, n) << ln;
    }
}
