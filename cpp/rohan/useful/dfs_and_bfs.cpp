#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj (n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // BFS
    auto bfs = [&](int root){
        queue<int> q;
        vector<bool> vis (n);
        
        q.push(root);
        vis[root] = true;

        while (!q.empty()) {
            int curr = q.front(); q.pop();
            for (int x : adj[curr]) {
                if (vis[x]) continue;
                vis[x] = true;
                q.push(x);
            }
        }
    };

    // DFS recursive
    vector<bool> vis (n);
    function<void(int)> dfs = [&](int curr) {
        if (vis[curr]) return;
        vis[curr] = true;
        for (int x : adj[curr])
            dfs(x);
    };

    // DFS with stack
    auto dfs = [&](int root){
        stack<int> st;
        vector<bool> vis (n);
        
        st.push(root);
        vis[root] = true;

        while (!st.empty()) {
            int curr = st.top(); st.pop();
            for (int x : adj[curr]) {
                if (vis[x]) continue;
                vis[x] = true;
                st.push(x);
            }
        }
    };
}
