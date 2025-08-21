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
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;

    vec<vec<int>> routes;
    bool isSorted = true;
    int prev = 0;
    for (int i = 0; i < n; i++) {
        // need path from i to p[i]
        int k; cin >> k; k--;
        routes.push_back({i, k});
        if (prev > k) isSorted = false;
        prev = k;
    }
    
    if (isSorted) {
        cout << "-1\n";
        return 0;
    }

    vec<vec<int>> edges (m, vec<int>(3));
    for (auto& e : edges) {
        // e = {weight, a, b}
        cin >> e[1] >> e[2] >> e[0];
        e[1]--; e[2]--;
    }
    sort(all(edges), greater<vec<int>>());
    // cout << edges << ln;

    // find largest minW that works
    function<bool(int)> valid = [&](int minW) {
        DisjointSets ds (n);
        for (int i = 0; i < m && edges[i][0] >= minW; i++) {
            ds.unite(edges[i][1], edges[i][2]);
        }
        for (vec<int>& route : routes) {
            if (!ds.connected(route[0], route[1]))
                return false;
        }
        return true;
    };

    auto lastTrue = [](int low, int high, function<bool(int)> f) {
        while (low < high) {
            int mid = (low+high+1) / 2;
            if (f(mid))
                low = mid;
            else
                high = mid - 1;
        }
        return low;
        // if (f(low)) return low;
        // return -1;
    };

    cout << lastTrue(-1, 1e9, valid) << ln;
}
