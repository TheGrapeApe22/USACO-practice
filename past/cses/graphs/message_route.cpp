#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using ll = long long;
void print(vector<int>& v) {cout << "["; for (auto& x : v) cout << x << " "; cout << "]\n";}

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;

    vector<vector<int>> neighbors (n);
    vector<bool> visited(n, false);
    vector<int> parent (n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        neighbors[a].push_back(b);
        neighbors[b].push_back(a);
    }

    // bfs from n-1 to 0
    queue<int> q;
    q.push(n-1);
    visited[n-1] = true;
    while (!q.empty()) {
        int curr = q.front();
        // cout << curr << " ";
        for (int x : neighbors[curr]) {
            if (visited[x]) continue;
            visited[x] = true;
            parent[x] = curr;
            q.push(x);
        }
        q.pop();
    }

    // cout << "\n";
    // print(neighbors[0]);
    // print(parent);

    if (!visited[0]) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    string out = "";
    int curr = 0;
    int count = 1;
    while (curr != n-1) {
        out += to_string(curr+1) + " ";
        curr = parent[curr];
        count++;
    }
    out += to_string(n);
    cout << count << "\n" << out << "\n";
}
