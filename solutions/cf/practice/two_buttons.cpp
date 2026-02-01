// https://codeforces.com/problemset/problem/520/B
// looked at solution

#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define _ << " " <<
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;

    vec<bool> visited (2e4);

    queue<pii> q;
    q.push({n, 0});
    while (q.size()) {
        auto [x, depth] = q.front();
        q.pop();
        if (x < 0 || x >= 2e4) continue;
        if (visited[x]) continue;
        visited[x] = true;

        if (x == m) {
            cout << depth << ln;
            break;
        }

        q.push({x-1, depth+1});
        q.push({x*2, depth+1});
    }
}
