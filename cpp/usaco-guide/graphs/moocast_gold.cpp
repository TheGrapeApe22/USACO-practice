#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define _ << " " <<
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using pii = pair<int, int>;
namespace {
    template<typename it> void print(it, it);
    template<typename T> void print(T& v) {print(all(v));}
    template<typename T, typename U> void print(pair<T, U> p) { cout << "("<<p.first<<", "<<p.second<<")"; }
    template<typename T, typename U>ostream& operator<<(ostream& out, pair<T, U> p) { print(p); return out; }
    template<typename T> ostream& operator<<(ostream& out, const vector<T>& v) { print(v); return out; }
    template<typename T> ostream& operator<<(ostream& out, const set<T>& v) { print(v); return out; }
    template<typename T> ostream& operator<<(ostream& out, const multiset<T>& v) { print(v); return out; }
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
class DisjointSets {
	public:
    vector<int> p;
	vector<int> rank;

	DisjointSets(int n) : p(n), rank(n, 1) {
		iota(all(p), 0);
	}

	int find(int x) {
        if (p[x] == x) return x;
        return p[x] = find(p[x]);
    }

	bool unite(int x, int y) {
		int xRoot = find(x), yRoot = find(y);
		if (xRoot == yRoot) return false;

		if (rank[xRoot] < rank[yRoot])
            swap(xRoot, yRoot);
        
		if (rank[xRoot] == rank[yRoot])
			rank[xRoot]++;
		p[yRoot] = xRoot;
		return true;
	}

	bool connected(int x, int y) { return find(x) == find(y); }
};

int main() {
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n;
    cin >> n;

    vec<vec<int>> cows (n, vec<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> cows[i][0] >> cows[i][1];
    }

    vec<vec<int>> edges;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            int dx = cows[i][0] - cows[j][0];
            int dy = cows[i][1] - cows[j][1];
            edges.push_back({dx*dx+dy*dy, i, j});
        }
    }
    sort(all(edges));

    DisjointSets ds (n);
    int i = 0;
    int dist = 0;
    for (auto& edge : edges) {
        if (i == n-1) break;
        if (ds.unite(edge[1], edge[2])) {
            dist = edge[0];
            i++;
        }
    }
    cout << dist << ln;
}
