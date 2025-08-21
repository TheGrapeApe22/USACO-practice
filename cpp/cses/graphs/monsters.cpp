#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define space << " " <<
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
namespace {
    template<typename it> void print(it, it);
    template<typename T> void print(T v) {print(all(v));}
    // ostream& operator<<(ostream& out, const pair<const int, int>& p) { cout << "("<<p.first<<", "<<p.second<<")"; return out; }
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
bool searchEdge(int r, int c, Point A) {
    if (board[r][c] == '#') return false;
    int n = board.size(), m = board[0].size();

    vec<vec<int>> depth (n, vec<int> (m, -1));
    vec<vec<char>> dir (n, vec<char> (m, ' '));

    queue<Point> q;
    q.push({r, c});
    depth[r][c] = 0;

    while (!q.empty()) {
        Point curr = q.front();
        q.pop();
        
        if (board[curr.x][curr.y] == 'M')
            return false;
        if (board[curr.x][curr.y] == 'A') {
            // check neighbor Ms
            if (curr != Point {r, c}) {
                Point prev = curr + getMove.at(dir[curr.x][curr.y]);
                for (int i = 0; i < 4; i++) {
                    Point next = prev + moves[i];
                    if (next.isInBounds(n, m) && board[next.x][next.y] == 'M')
                        return false;
                }
            }

            cout << "YES\n";
            cout << depth[curr.x][curr.y] << ln;
            while (curr != Point {r, c}) {
                char d = dir[curr.x][curr.y];
                curr += getMove.at(d);
                cout << d;
            }
            cout << ln;
            return true;
        }

        for (int i = 0; i < 4; i++) {
            Point next = moves[i] + curr;
            if (!next.isInBounds(n, m)) continue;
            if (board[next.x][next.y] == '#') continue;
            if (depth[next.x][next.y] != -1) continue;

            // continue search
            depth[next.x][next.y] = depth[curr.x][curr.y]+1;
            dir[next.x][next.y] = letters[(i + 2)%4];
            q.push(next);
        }
    }
    return false;
}

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;

    Point A;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        board.push_back(s);

        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'A')
                A = {i, j};
        }
    }

    vec<Point> edges;
    

    cout << "NO\n";
}
