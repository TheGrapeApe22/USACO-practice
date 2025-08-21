#include <bits/stdc++.h>
#define vec vector
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;

template<typename it> void print(it, it);
template<typename T> void print(T v) {print(all(v));}
ostream& operator<<(ostream& out, const pair<const int, int>& p) { cout << "("<<p.first<<", "<<p.second<<")"; return out; }
// copy/paste for any container
template<typename T> ostream& operator<<(ostream& out, const vector<T>& v) { print(v); return out; }
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

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n, m, k;
    cin >> n >> m >> k;

    vec<int> nums (n);
    vec<vec<int>> ops (m, vec<int> (3)); // ops[i] = [l, r, d]
    vec<int> countOps (m, 0);

    // input nums and ops
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> ops[i][j];
            if (j < 2) ops[i][j]--;
        }
    }

    // input queries
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        countOps[a]++;
        if (b+1 < m)
            countOps[b+1]--;
    }
    
    // build prefix sum
    for (int i = 1; i < m; i++)
        countOps[i] += countOps[i-1];

    vec<int> add (n);
    for (int i = 0; i < m; i++) {
        auto& op = ops[i];
        int start = op[0];
        int end = op[1] + 1;
        int d = op[2] * countOps[i];
        
        add[start] += d;
        if (end < n)
            add[end] -= d;
    }
    
    for (int i = 0; i < n; i++) {
        if (i > 0)
            add[i] += add[i-1]; // prefix sum 2
        cout << (nums[i] + add[i]) << " ";
    }
    cout << "\n";
}
