/*
O(n^3)
construct graph
	vector cows;
	for each cow (curr):
		for each other cow (x):
			if x can transmit to curr, connect
			if curr can transmit to x, connect
		add curr to cows
for each cow
	count how many cows it can reach
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

int main() {
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n;
    cin >> n;

    vec<vec<int>> adj (n);
    vec<vec<int>> cows;
    for (int i = 0; i < n; i++) {
        int x, y, r;
        cin >> x >> y >> r;

        auto square = [](int x) {return x*x;};
        for (vec<int>& cow : cows) {
            int dist = square(x-cow[1])+square(y-cow[2]);
            if (dist <= r*r)
                adj[i].push_back(cow[0]);
            if (dist <= square(cow[3]))
                adj[cow[0]].push_back(i);
        }

        cows.push_back({i, x, y, r});
    }

    int highest = 1;
    for (int i = 0; i < n; i++) {
        int count = 0;
        vector<bool> vis (n);
        function<void(int)> dfs = [&](int curr) {
        if (vis[curr]) return;
            vis[curr] = true;
            count++;
            for (int x : adj[curr])
                dfs(x);
        };
        
        dfs(i);
        highest = max(highest, count);
    }
    cout << highest << ln;
}
