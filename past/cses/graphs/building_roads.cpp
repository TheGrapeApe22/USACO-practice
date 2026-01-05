#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m;
const int N = 1e5, M = 2e5;

vector<vector<int>> neighbors(N);
vector<bool> visited(N, false);

void dfs(int curr) {
    for (int x : neighbors[curr]) {
        if (visited[x]) continue;
        visited[x] = true;
        dfs(x);
    }
}

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    cin >> n >> m;
    
    // neighbors (n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        neighbors[a].push_back(b);
        neighbors[b].push_back(a);
    }
    
    int count = 0;
    string out = "";
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (i != 0) {
                out += "1 " + to_string(i+1) + "\n";
                count++;
            }
            dfs(i);
        }
    }

    // for (int i = 0; i < n; i++)
    //     cout << visited[i];
    cout << "\n";
    cout << count << "\n" << out;
}
