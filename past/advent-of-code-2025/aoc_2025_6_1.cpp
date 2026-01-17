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
    
    // n = columns, m = number of number rows
    // int n, m; cin >> n >> m;
    int n = 491+509;
    int m = 4;
    
    string operators;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        operators += s;
    }

    vec<ll> totals (n);
    for (int i = 0; i < n; i++) {
        if (operators[i] == '*')
            totals[i] = 1;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            ll k; cin >> k;
            // cout << k << ln;
            if (operators[j] == '*')
                totals[j] *= k;
            else
                totals[j] += k;
        }
    }
    
    ll sum = 0;
    for (ll x : totals) sum += x;
    // cout << totals << ln;
    cout << sum << ln;
}
