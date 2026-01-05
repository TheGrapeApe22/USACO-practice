// https://usaco.guide/silver/graph-traversal?lang=cpp
// stupid solution again

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
    bool isSingle(int x) {
        return rank[find(x)] == 1;
    }
};

void solve(vec<int> v) {
    int n = v.size();
    
    DisjointSets ds (n);
    int open = 0, closed = 0;
    for (int i = 0; i < n; i++) {
        int j = v[i];
        if (v[j] == i && i > j) continue;
        
        if (ds.isSingle(i) && ds.isSingle(j))
            open++;
        if (ds.connected(i, j)) {
            closed++; open--;
        }
        else if (!ds.isSingle(i) && !ds.isSingle(j)) {
            open--;
        }
        ds.unite(i, j);
    }

    // cout << closed _ open << ln;
    cout << closed+(open>0) _ closed+open << ln;
}

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int t; cin >> t;

    for (int i = 0; i < t; i++) {
        int n; cin >> n;
        vec<int> v(n);
        for (int& x : v) {
            cin >> x;
            x--;
        }
        solve(v);
    }
}
