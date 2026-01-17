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
    
    vec<string> map;
    string s;
    while (cin >> s) {
        map.push_back(s);
    }

    int n = map.size();
    int m = map[0].size();

    auto inBounds = [&](int i, int j) {
        return i>=0 && j>=0 && i<n && j<m;
    };
    vec<pii> surrounding = {
        {-1, 0},
        {-1, -1},
        {-1, 1},
        {0, 1},
        {0, -1},
        {1, -1},
        {1, 1},
        {1, 0},
    };
    int count = 0;
    int currCount = 676767;
    while (currCount > 0) {
        currCount = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] != '@') continue;
                int neighbors = 0;
                for (auto [a, b] : surrounding) {
                    if (inBounds(i+a, j+b) && map[i+a][j+b] == '@')
                        neighbors++;
                }
                if (neighbors < 4) {
                    map[i][j] = 'x';
                    currCount++;
                }
            }
        }
        count += currCount;
    }
    cout << count << endl;
}
