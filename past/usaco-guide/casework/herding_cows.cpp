// https://usaco.org/index.php?page=viewproblem2&cpid=915
// i am so stupid.
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
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    
    vec<int> cows (3);
    cin >> cows[0] >> cows[1] >> cows[2];
    sort(all(cows));
    int a = cows[0], b = cows[1], c = cows[2];

    // if b-a = 1 and c-b = 1: min = max = 0
    if (b-a == 1 && c-b == 1) {
        cout << 0 << ln << 0 << ln;
        return 0;
    }
    if (b-a == 2 || c-b == 2)
        cout << 1 << ln;
    else
        cout << 2 << ln;
    cout << max(b-a, c-b)-1 << ln;
}
