/*
dp(n, m) = min:
    dp(n-1, m-1) + (n != m)
    dp(n-1, m) + 1
    dp(n, m-1) + 1

dp(x, 0) = x
dp(0, x) = x
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

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    string a, b;
    cin >> a >> b;

    int n = a.size(), m = b.size();

    vec<vec<int>> dp (n+1, vec<int>(m + 1, -1));

    for (int i = 0; i <= m; i++)
        dp[0][i] = i;
    for (int i = 0; i <= n; i++)
        dp[i][0] = i;
    
    function<int(int, int)> solve = [&](int n, int m) {
        if (dp[n][m] != -1) return dp[n][m];
        if (a[n-1] == b[m-1]) return solve(n-1, m-1);
        int ans = 1 + min(min(solve(n-1, m), solve(n, m-1)), solve(n-1, m-1));
        dp[n][m] = ans;
        return ans;
    };

    cout << solve(n, m) << ln;
}
