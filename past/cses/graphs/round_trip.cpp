#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;

template<typename it> void print(it, it);
template<typename T> void print(T v) {print(all(v));}
ostream& operator<<(ostream& out, const pair<const int, int>& p) { cout << "("<<p.first<<", "<<p.second<<")"; return out; }
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

const int N = 1e5;
vec<vec<int>> adj (N);
vec<int> par (N, -1);

bool dfs (int curr, int myPar) {
    for (int next : adj[curr]) {
        if (next == myPar) continue;
        if (next == 0 || par[next] != -1) {
            vec<int> out;
            out.push_back(next);
            while (curr != next) {
                // cout << curr << endl;
                out.push_back(curr);
                curr = par[curr];
            }
            out.push_back(next);
            cout << out.size() << ln;
            for (int x : out)
                cout << x+1 << " ";
            cout << ln;
            return true;
        }
        par[next] = curr;
        if (dfs(next, curr))
            return true;
    }
    return false;
}

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool found = false;
    for (int i = 0; i < n; i++) {
        if (par[i] == -1) {
            found = found || dfs(i, -1);
            if (found) break;
        }
    }
    if (!found) cout << "IMPOSSIBLE\n";
}
