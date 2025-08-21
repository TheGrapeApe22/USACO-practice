#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

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
