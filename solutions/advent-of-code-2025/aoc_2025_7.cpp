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
    
    int n = 142; n--;
    string S; cin >> S;
    int m = S.size();

    vec<ll> beams (m);

    for (int i = 0; i < m; i++) {
        if (S[i] == 'S')
            beams[i] = 1;
    }

    for (int r = 0; r < n; r++) {
        string s; cin >> s;
        for (int i = 0; i < m; i++) {
            if (s[i] == '^') {
                if (i-1 >= 0)
                    beams[i-1] += beams[i];
                if (i+1 < m)
                    beams[i+1] += beams[i];
                beams[i] = 0;
            }
        }
    }
    
    // cout << beams << ln;
    ll sum = 0;
    for (ll x : beams) sum += x;
    cout << sum << ln;
}
