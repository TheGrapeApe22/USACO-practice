#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using pii = pair<int, int>;

class DisjointSets {
	public:
    vector<int> p;
	vector<int> s;
    vector<int> mins;
    vector<int> maxes;

	DisjointSets(int n) : p(n), s(n, 1), mins(n), maxes(n) {
		iota(all(p), 0);
        iota(all(mins), 0);
        iota(all(maxes), 0);
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
        
        mins[xRoot] = min(mins[xRoot], mins[yRoot]);
        maxes[xRoot] = max(maxes[xRoot], maxes[yRoot]);
		s[xRoot] += s[yRoot];
		p[yRoot] = xRoot;
		return true;
	}

	bool connected(int x, int y) { return find(x) == find(y); }
};

int main() {
    int n, q;
    cin >> n >> q;

    DisjointSets ds (n);

    for (int i = 0; i < q; i++) {
        string s;
        cin >> s;
        
        if (s == "get") {
            int x; cin >> x;
            x--;
            x = ds.find(x);
            cout << ds.mins[x]+1 << " " << ds.maxes[x]+1 << " " << ds.s[x] << ln;
        }
        else {
            int a, b;
            cin >> a >> b;
            a--; b--;
            ds.merge(a, b);
        }
    }
}
