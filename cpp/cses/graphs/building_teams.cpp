#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void print(vector<int>& v, int n=-1) {if (n == -1) n = v.size(); cout << "["; for (int i = 0; i < n; i++) cout << v[i] << " "; cout << "]\n";}
void print(int a, int b) {cout << "(" << a << ", " << b << ")\n";}

const int N = 2e5;
vector<vector<int>> neighbors (N);
vector<int> assign (N, 0);
bool conflict = false;

void bfs (int curr) {
    int nextAssign = (assign[curr] == 1) ? 2 : 1;
    
    for (int x : neighbors[curr]) {
        if (assign[x] == 0) {        
            assign[x] = nextAssign;
            bfs(x);
        }
        else if (assign[x] != nextAssign) {
            // conflict
            conflict = true;
        }
    }
}

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        neighbors[a].push_back(b);
        neighbors[b].push_back(a);
    }

    // iterate
    for (int i = 0; i < n; i++) {
        if (assign[i] == 0) {
            assign[i] = 1;
            bfs(i);
        }
    }

    if (conflict) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    // output
    for (int i = 0; i < n; i++)
        cout << assign[i] << " ";
    cout << endl;
}
