#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
namespace {
    template<typename it> void print(it, it);
    template<typename T> void print(T v) {print(all(v));}
    template<typename T, typename U>ostream& operator<<(ostream& out, const pair<const T, U>& p) { cout << "("<<p.first<<", "<<p.second<<")"; return out; }
    template<typename T> ostream& operator<<(ostream& out, const vector<T>& v) { print(v); return out; }
    template<typename T> ostream& operator<<(ostream& out, const set<T>& v) { print(v); return out; }
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
    
    int n, m;
    cin >> n >> m;

    vec<int> cities (n);
    vec<int> towers (m);

    for (int& x : cities) cin >> x;
    for (int& x : towers) cin >> x;

    int r = 0;
    for (int x : cities) {
        int minR = 2147483647;

        auto right = lower_bound(all(towers), x);
        if (right != towers.end()) {
            // cout << *right - x << endl;
            minR = min(minR, *right - x);
        }
        
        auto left = upper_bound(all(towers), x);
        if (left != towers.begin()) {
            left--;
            // cout << x - *left << endl;
            minR = min(minR, x - *left);
        }

        r = max(r, minR);
    }

    cout << r << ln;
}
