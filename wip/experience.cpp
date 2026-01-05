/*
LATEST ATTEMPT
getVal(x):
	if (p[x] == x)
		return val[x]
	if (p[p[x]] != p[x]) // if p[x] isn't root
		val[x] += getVal(p[x])
		p[x] = p[p[x]]
	return getVal(p[x]) + val[x]

add(x, c):
	val[root(x)] += c

join(x, y):
	px = root(x)
	val[y] -= getVal(px)
	p[y] = px
*/

#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
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

/*
getVal(x):
	if (p[x] == x)
		return val[x]
	if (p[p[x]] != p[x]) // if p[x] isn't root
		val[x] += getVal(p[x])
		p[x] = p[p[x]]
	return getVal(p[x]) + val[x]

add(x, c):
	val[root(x)] += c

join(x, y):
	px = root(x)
	val[y] -= getVal(px)
	p[y] = px

*/

class DisjointSets {
	public:
    vector<int> p, rank, val;

	DisjointSets(int n) : p(n), rank(n, 1), val(n) {
		iota(all(p), 0);
	}

	int getVal(int x) {
        if (p[x] == x)
			return val[x];
		if (p[p[x]] != p[x]) {
			val[x] += getVal(p[x]);
			p[x] = p[p[x]];
		}
        // cout << val << ln;
		return getVal(p[x]) + val[x];
    }

    int root(int x) {
        getVal(x);
        return p[x];
    }

	void unite(int x, int y) {
		int xRoot = root(x), yRoot = root(y);
		if (xRoot == yRoot) return;

		if (rank[xRoot] < rank[yRoot])
            swap(xRoot, yRoot);
        
		if (rank[xRoot] == rank[yRoot])
			rank[xRoot]++;
        val[yRoot] -= getVal(xRoot);
		p[yRoot] = xRoot;
	}

    void add(int x, int c) {
        val[root(x)] += c;
    }
};

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n, q;
    cin >> n >> q;

    DisjointSets ds (n);

    for (int i = 0; i < q; i++) {
        string s; cin >> s;
        if (s == "get") {
            int x; cin >> x;
            cout << ds.getVal(x-1) << ln;
        }
        else {
            int a, b;
            cin >> a >> b;
            if (s == "join")
                ds.unite(a-1, b-1);
            else
                ds.add(a-1, b);
        }
    }
}
