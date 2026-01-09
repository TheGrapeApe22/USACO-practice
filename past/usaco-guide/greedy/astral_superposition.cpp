// https://usaco.org/index.php?page=viewproblem2&cpid=1467
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
W: none
G: one
B: both

B at (x,y) means og has (x, y) and (x-a, y-b)
W at (x,y) means og does't have (x, y) or (x-a, y-b)
G at (x,y) means x<a or y<b or og only one out of [(x,y) (x-a, y-b)]
*/

int solve(vec<string> prints, int n, int a, int b) {
    vec<vec<int>> stars (n, vec<int>(n, 0));
    // 0=don't know, 1=has star, 2=doesn't have star
    auto inBounds = [&](int x, int y){ return x>=0 && y>=0 && x<n && y<n; };
    auto setStar = [&](int x, int y, int val) {
        if (inBounds(x, y)) {
            if (stars[x][y] != 0 && stars[x][y] != val)
                return false;
            stars[x][y] = val;
        }
        return true;
    };
    auto debug = [&]() {
        // for (int y = 0; y < n; y++) {for (int x = 0; x < n; x++) {cout << stars[y][x];}cout << ln;}cout << endl;
    };
    // B at (x,y) means og has (x, y) and (x-a, y-b)
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (prints[y][x] == 'B') {
                if (!setStar(y, x, 1)) return -1;
                if (!inBounds(y-b, x-a)) return -1; // og has to have (x-a, y-b)
                if (!setStar(y-b, x-a, 1)) return -1;
            }
        }
    }
    
    debug();

    // W at (x,y) means og does't have (x, y)
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (prints[y][x] == 'W') {
                if (!setStar(y, x, 2)) return -1;
            }
        }
    }
    
    debug();

    // G at (x,y) means only one out of [(x,y) (x-a, y-b)]
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (prints[y][x] == 'G') {
                if (y<b || x<a) {
                    if (!setStar(y, x, 1)) return -1;
                }
                // if og doesn't have (x-a, y-b), og has to have (x,y) to satisfy gray
                else if (stars[y-b][x-a] == 2) {
                    if (!setStar(y, x, 1)) return -1;
                }
                // if og has (x-a, y-b), og could be either, so set to (no star)
                else if (stars[y-b][x-a] == 1) {
                    setStar(y, x, 2); // could possibly reject, that's intended
                }
                else {
                    // i guess this is the edge case where a=0, b=0
                    setStar(y, x, 1);
                }
            }
        }
    }

    debug();
    int count = 0;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (stars[y][x] == 1) count++;
        }
    }
    return count;
}

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int t;
    cin >> t;

    for (int t1 = 0; t1 < t; t1++) {
        int n, a, b;
        cin >> n >> a >> b;
        vec<string> prints (n);
        for (string& line : prints)
            cin >> line;

        cout << solve(prints, n, a, b) << ln;
    }
}
