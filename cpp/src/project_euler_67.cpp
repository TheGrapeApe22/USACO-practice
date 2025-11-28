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
int N = 100;
int main() {
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    vec<vec<int>> sums (N, vec<int> (N));
    for (int n = 1; n <= N; n++) {
        for (int j = 0; j < n; j++)
            cin >> sums[n-1][j];
        if (n == 1) continue;
        for (int j = 0; j < n; j++) {
            int add = sums[n-2][j];
            if (j-1 >= 0)
                add = max(add, sums[n-2][j-1]);    
            sums[n-1][j] += add;
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++)
        ans = max(ans, sums[N-1][i]);
    cout << ans << ln;
}
