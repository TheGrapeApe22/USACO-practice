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
    // freopen("helpcross.in", "r", stdin);
    // freopen("helpcross.out", "w", stdout);
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    // collect input
    int c, n;
    cin >> c >> n;

    vec<int> times (c);
    for (int i = 0; i < c; i++)
        cin >> times[i];

    vec<pii> ranges (n);
    for (int i = 0; i < n; i++)
        cin >> ranges[i].first >> ranges[i].second;
    
    sort(all(ranges));
    sort(all(times));
    // cout << times << ln << ranges << ln;

    priority_queue<int, vec<int>, greater<int>> pq;
    int count = 0;
    int j = 0;
    for (int t : times) {
        while (j < n && ranges[j].first <= t) {
            pq.push(ranges[j].second);
            j++;
        }
        while (!pq.empty() && pq.top() < t)
            pq.pop();
        if (pq.empty()) continue;
        pq.pop();
        count++;
    }
    cout << count << ln;
}
