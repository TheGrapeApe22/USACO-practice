#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define _ << " " <<
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

long long value (char c) {
    if (islower(c))
        return c - 'a' + 1;
    return c - 'A' + 27;
}
ll MOD = 998244353;
int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    long long a = 1;
    long long A = 0;
    vec<pii> dp (1e4 + 1);
    for (long long i = 0; i <= 1e4; i++) {
        long long temp = a;
        a = A;
        A += temp;
        a %= MOD;
        A %= MOD;
        dp[i] = {a,A};
    }
    // cout << dp << endl;

    long long n;
    cin >> n;

    for (long long t = 0; t < n; t++) {
        string s; long long k;
        cin >> s >> k;
        
        long long total = 0;
        for (long long i = 0; i < s.size(); i++) {
            if (islower(s[i])) {
                total += value(s[i]) * dp[k-1].first + value(toupper(s[i])) * dp[k-1].second;
                total %= MOD;
            }
            else {
                total += value(s[i]) * dp[k].second + value(tolower(s[i])) * dp[k].first;
                total %= MOD;
            }
        }
        cout << total << ln;
    }
}
