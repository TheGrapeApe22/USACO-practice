#include <bits/stdc++.h>
using namespace std;

const vector<char> letters {'R', 'D', 'L', 'U'};
const vector<Point> moves {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
struct Point {
    int x = 0, y = 0;

    Point operator+ (const Point& p) const { return {x + p.x, y + p.y}; }
    Point operator+= (const Point& p) { *this = *this + p; }
    bool operator== (const Point& p) const { return x == p.x && y == p.y; }
    bool operator!= (const Point& p) const { return !(*this == p); }
    bool isInBounds(int n, int m) const { return x >= 0 && y >= 0 && x < n && y < m; }
    string toString() const { return "(" + to_string(x) + ", " + to_string(y) + ")"; }
};
