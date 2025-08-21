#include <bits/stdc++.h>
#define vec vector
#define all(x) (x).begin(), (x).end()
#define ln "\n";
using namespace std;
using ll = long long;

template<typename it> void print(it, it);
template<typename T> void print(T v) {print(all(v));}
ostream& operator<<(ostream& out, const pair<const int, int>& p) { cout << "("<<p.first<<", "<<p.second<<")"; return out; }
// copy/paste for any container
template<typename T> ostream& operator<<(ostream& out, const vector<T>& v) { print(v); return out; }
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

int main() {
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);

    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n, k;
    cin >> n >> k;
    int N = 1001;

    vec<vec<int>> v (N+1, vec<int> (N+1));

    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a++; b++; c++; d++;
        v[a][b]++;
        v[a][d]--;
        v[c][b]--;
        v[c][d]++;
    }
    // for (auto& z : v)
    //     cout << z << "\n";
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            v[i][j] += v[i-1][j] + v[i][j-1] - v[i-1][j-1];
        }
    }

    // cout << endl;
    // for (auto& z : v)
    //     cout << z << "\n";
    int count = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (v[i][j] == k) count++;
        }
    }
    cout << count << ln;
}
