#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Point {
    int x = 0; int y = 0;
    // string path = "";
    Point operator+ (const Point& p) const { return {x + p.x, y + p.y}; }
    bool operator== (const Point& p) const { return x == p.x && y == p.y; }
    bool isInBounds(int n, int m) const { return x >= 0 && y >= 0 && x < n && y < m; }
    string toString() const { return "(" + to_string(x) + ", " + to_string(y) + ")"; }
};

int n, m;
Point a, b;
constexpr int N = 1000, M = 1000;

vector<string> board (N);
vector<vector<bool>> visited (N, vector<bool>(M));
vector<vector<char>> paths (N, vector<char>(M, ' '));

const vector<char> letters = {'R', 'D', 'L', 'U'};
const vector<Point> moves = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void bfs() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    visited[a.x][a.y] = true;

    queue<Point> q;
    q.push(a);

    while (!q.empty()) {
        Point curr = q.front();
        if (curr == b) {
            cout << "YES\n";
            string path = "";
            Point p = b;
            while (!(p == a)) {
                int i = 0;
                while (letters[i] != paths[p.x][p.y])
                    i++;
                p = p + moves[i];
                path += letters[i];
            }

            cout << path.size() << "\n" << path << "\n";
            // for (int i = 0; i < n; i++) {
            //     for (int j = 0; j < m; j++)
            //         cout << paths[i][j];
            //     cout << "\n";
            // }
            return;
        }
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            Point next = curr + moves[i];
            if (!next.isInBounds(n, m)) continue;
            if (board[next.x][next.y] == '#') continue;
            if (visited[next.x][next.y]) continue;

            visited[next.x][next.y] = true;
            paths[next.x][next.y] = letters[(i+2)%4];
            q.push(next);
        }
    }
    cout << "NO\n";
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> board[i];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'B') {
                a.x = i; a.y = j;
            }
            else if (board[i][j] == 'A') {
                b.x = i; b.y = j;
            }
        }
    }

    bfs();
}
