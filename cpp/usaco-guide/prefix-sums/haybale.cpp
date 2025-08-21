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
    
    int n, k;
    cin >> n >> k;

    vec<int> v (n);
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        v[a]++;
        if (b+1 < n)
            v[b+1]--;
    }
    for (int i = 1; i < n; i++)
        v[i] += v[i-1];
    
    sort(all(v));
    cout << v[n/2] << "\n";

}
