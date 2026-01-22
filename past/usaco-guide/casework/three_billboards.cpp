// https://codeforces.com/problemset/problem/581/D
// ragebait problem

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

struct board {
    int x; int y;
    char letter;
    void print() {
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++)
                cout << string {letter};
            cout << ln;
        }
    }
    ostream& operator<< (ostream& out) {
        cout << string {letter} << ": " << x _ y << ln;
        return out;
    }
};

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    if (false) {
        die:
        cout << -1 << ln;
        return 0;
    }

    board a, b, c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    a.letter = 'A'; b.letter = 'B'; c.letter = 'C';

    if (a.x < a.y) swap(a.x, a.y);
    if (b.x < b.y) swap(b.x, b.y);
    if (c.x < c.y) swap(c.x, c.y);

    // check if all 3 have same width
    if (a.x == b.x && b.x == c.x) {
        // if they do, if their heights add up then print
        if (a.y + b.y + c.y == a.x) {
            cout << a.x << ln;
            a.print();
            b.print();
            c.print();
            return 0;
        }
        // if not, then -1
        else goto die;
    }

    // biggest side = size of square
    if (a.x < b.x) swap(a, b);
    if (a.x < c.x) swap(a, c);
    // rotate the other two to match the remaining height. if not doable, then -1
    int remainingY = a.x - a.y;
    
    if (b.y == remainingY);
    else if (b.x == remainingY) swap(b.x, b.y);
    else goto die;
    
    if (c.y == remainingY);
    else if (c.x == remainingY) swap(c.x, c.y);
    else goto die;
    
    // check if their widths add up to size of square. if not, then -1
    if (b.x + c.x == a.x);
    else goto die;

    // yippee
    cout << a.x << ln;
    a.print();
    for (int i = 0; i < b.y; i++) {
        for (int j = 0; j < b.x; j++)
            cout << b.letter;
        for (int j = 0; j < c.x; j++)
            cout << c.letter;
        cout << ln;
    }
}
