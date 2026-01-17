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

struct point {
    int id, x, y, z;
};
ll sq(int x) {
    return (ll)x * x;
}
ll dist(point a, point b) {
    return sq(a.x-b.x) + sq(a.y-b.y) + sq(a.z-b.z);
}

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n; cin >> n;
    vec<point> points (n);
    int id = 0;
    for (auto& p : points) {
        p.id = id++;
        cin >> p.x >> p.y >> p.z;
    }

    vec<pair<ll, pii>> distances;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            distances.push_back({dist(points[i], points[j]), {points[i].id, points[j].id}});
        }
    }

    sort(all(distances));
    vec<vec<int>> adj (n);
    for (int i = 0; i < n; i++) {
        auto [a, b] = distances[i].second;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    DisjointSets ds (n);
    int numConnections = 0;
    for (auto z : distances) {
        auto [a, b] = z.second;
        if (ds.unite(a, b)) numConnections++;
        if (numConnections == n-1) {
            cout << a _ b << ln;
            cout << points[a].x _ points[b].x << ln;
            cout << (ll)points[a].x * points[b].x << ln;
            break;
        }
    }
}
