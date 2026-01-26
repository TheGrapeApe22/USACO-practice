// https://codeforces.com/contest/1777/problem/C
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
pointers l=0, r
loop:
    while [l, r] incomplete, r++
    count ans
    l++
*/

vec<vec<int>> factors (1e5+1, vec<int>{1});

void solve(int n, int m, vec<int>& a) {
    vec<int> freq (m+1);
    int count = 0;
    int ans = 1e9;

    for (int l = 0, r = 0; l < n; l++) {
        // while [l, r] incomplete, r++
        while (count < m && r < n) {
            // add factors of a[r] to freq
            for (int factor : factors[a[r]]) {
                if (factor > m) continue;
                if (freq[factor] == 0)
                    count++;
                freq[factor]++;
            }
            r++;
        }

        // count ans
        if (count >= m)
            ans = min(ans, a[r-1]-a[l]);

        // l++
        for (int factor : factors[a[l]]) {
            if (factor > m) continue;
            freq[factor]--;
            if (freq[factor] == 0)
                count--;
        }
    }
    if (ans == 1e9) ans = -1;
    cout << ans << ln;
}


int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    for (int x = 2; x <= 1e5; x++) {
        for (int mult = x; mult <= 1e5; mult += x)
            factors[mult].push_back(x);
    }
    
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;
        vec<int> a (n);
        for (int& x : a) cin >> x;
        sort(all(a));
        solve(n, m, a);
    }
}
