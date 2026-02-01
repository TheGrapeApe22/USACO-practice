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

struct Point {
    int x = 0, y = 0;

    Point operator+ (const Point& p) const { return {x + p.x, y + p.y}; }
    Point operator+= (const Point& p) { *this = *this + p; return *this; }
    bool operator== (const Point& p) const { return x == p.x && y == p.y; }
    bool operator!= (const Point& p) const { return !(*this == p); }
    bool isInBounds(int n, int m) const { return x >= 0 && y >= 0 && x < n && y < m; }
    string toString() const { return "(" + to_string(x) + ", " + to_string(y) + ")"; }
};
const vector<char> letters {'R', 'D', 'L', 'U'};
const vector<Point> moves {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
const map<char, Point> getMove {{'R', moves[0]}, {'D', moves[1]}, {'L', moves[2]}, {'U', moves[3]}};

vec<string> board;

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;

    Point A;
    queue<Point> monsters;
    vec<vec<int>> mDepth (n, vec<int> (m, -1));

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        board.push_back(s);

        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'A')
                A = {i, j};
            if (board[i][j] == 'M') {
                monsters.push({i, j});
                mDepth[i][j] = 0;
            }
        }
    }

    // bfs from monsters
    while (!monsters.empty()) {
        Point curr = monsters.front();
        monsters.pop();

        for (int i = 0; i < 4; i++) {
            Point next = curr + moves[i];
            if (!next.isInBounds(n, m)) continue;
            if (board[next.x][next.y] == '#') continue;
            if (mDepth[next.x][next.y] != -1) continue;
            mDepth[next.x][next.y] = mDepth[curr.x][curr.y] + 1;
            monsters.push(next);
        }
    }

    // for (auto z : mDepth)
    //     cout << z << ln;

    // bfs from A
    vec<vec<int>> aDepth (n, vec<int> (m, -1));
    vec<vec<char>> dir (n, vec<char> (m, ' '));
    queue<Point> q;
    q.push(A);
    aDepth[A.x][A.y] = 0;
    while (!q.empty()) {
        Point curr = q.front();
        q.pop();

        if (aDepth[curr.x][curr.y] >= mDepth[curr.x][curr.y] && mDepth[curr.x][curr.y] != -1)
            continue;

        if (curr.x == 0 || curr.x == n-1 || curr.y == 0 || curr.y == m-1) {
            // cout << curr.toString() << ln;
            if (aDepth[curr.x][curr.y] <= mDepth[curr.x][curr.y] || mDepth[curr.x][curr.y] == -1) {
                cout << "YES\n";
                string out = "";
                while (curr != A) {
                    char d = dir[curr.x][curr.y];
                    out += d;
                    curr += getMove.at(d);
                }
                cout << out.size() << ln;
                for (int i = out.size() - 1; i >= 0; i--) {
                    if (out[i] == 'U') cout << 'D';
                    else if (out[i] == 'D') cout << 'U';
                    else if (out[i] == 'R') cout << 'L';
                    else cout << 'R';
                }
                cout << ln;

                return 0;
            }
        }

        for (int i = 0; i < 4; i++) {
            Point next = moves[i] + curr;
            if (!next.isInBounds(n, m)) continue;
            if (board[next.x][next.y] != '.') continue;
            if (aDepth[next.x][next.y] != -1) continue;

            aDepth[next.x][next.y] = aDepth[curr.x][curr.y] + 1;
            dir[next.x][next.y] = letters[(i+2)%4];

            q.push(next);
        }
    }

    cout << "NO\n";
}
