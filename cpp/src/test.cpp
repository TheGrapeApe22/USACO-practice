#include <bits/stdc++.h>
using namespace std;

class DisjointSets {
	public:
    vector<int> p;
	vector<int> s;

	DisjointSets(int n) : p(n), s(n, 1) {
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
		p[yRoot] = xRoot;
		return true;
	}

	bool connected(int x, int y) { return find(x) == find(y); }
};

int main() {
    
}
