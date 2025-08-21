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

class DisjointSets {
	public:
    vector<int> p;
	vector<int> s;
    int maxSize = 1;
    int numGroups = 0;

	DisjointSets(int n) : p(n), s(n, 1) {
        numGroups = n;
		for (int i = 0; i < n; i++)
            p[i] = i;
	}

	int find(int x) {
        if (p[x] == x) return x;
        return p[x] = find(p[x]);
    }

	bool merge(int x, int y) {
		int xRoot = find(x), yRoot = find(y);
		if (xRoot == yRoot) return false;

		if (s[xRoot] < s[yRoot])
            swap(xRoot, yRoot);
        
		s[xRoot] += s[yRoot];
        maxSize = max(maxSize, s[xRoot]);
        numGroups--;
		p[yRoot] = xRoot;
		return true;
	}

	bool connected(int x, int y) { return find(x) == find(y); }
};

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;

    DisjointSets ds (n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        ds.merge(a, b);
        cout << ds.numGroups << " " << ds.maxSize << "\n";
    }
}
