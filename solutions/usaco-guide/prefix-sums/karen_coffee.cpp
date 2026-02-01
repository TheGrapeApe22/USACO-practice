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
    
    int n, k, q;
    cin >> n >> k >> q;

    vec<int> v (2e5+1, 0);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v[a]++;
        v[b + 1]--;
    }

    for (int i = 1; i < (int)v.size(); i++)
        v[i] += v[i-1];
    
    for (int i = 1; i < (int)v.size(); i++) {
        v[i] = (v[i] >= k) ? 1 : 0;
        v[i] += v[i-1];
    }
    
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << v[b] - v[a-1] << "\n";
    }

    // for (int i = 90; i <= 100; i++)
    //     cout << v[i] << " ";
}
