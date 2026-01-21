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
    every RL will remain full forever
    besides those, add up each chain of 1 letter e.g. RRRR and treat it as a single big bucket that depletes by -t
    only edge case: entire string is only one letter
*/

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    ll n, t;
    string dirs;
    cin >> n >> t >> dirs;

    vec<ll> cap (n); // capacity
    for (ll& x : cap) cin >> x;

    // find first RL
    ll offset = -1LL;
    for (ll i = 0LL; i < n; i++) {
        if (dirs[i] == 'R' && dirs[(i+1LL)%n] == 'L') {
            offset = i;
            break;
        }
    }
    if (offset == -1LL) {
        ll sum = 0LL;
        for (ll x : cap) sum += x;
        cout << sum << ln;
        return 0LL;
    }

    ll total = 0LL;
    char currChar = '_';
    ll currCap = 0LL;
    for (ll ii = 0LL; ii < n; ii++) {
        ll i = (ii+offset)%n;
        ll j = (i+1LL)%n;
        if (dirs[i] == 'R' && dirs[j] == 'L') {
            total += max(currCap - t, 0LL);
            total += cap[i] + cap[j];
            currChar = '_';
            currCap = 0LL;
            ii++;
            continue;
        }
        if (currChar == '_')
            currChar = dirs[i];
        if (currChar == dirs[i])
            currCap += cap[i];
        else {
            total += max(currCap - t, 0LL);
            currChar = dirs[i];
            currCap = cap[i];
        }
        // cout << i _ currCap _ total << ln;
    }
    total += max(currCap - t, 0LL);
    cout << total << ln;
}
