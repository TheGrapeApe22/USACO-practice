/*
push all nums into pq

sum = x

while (pq.size() > 1) {
    int a, b = pq.pop(), pq.pop()
    sum += a+b
    pq.push(a+b)
}
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
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int x, n;
    cin >> x >> n;

    priority_queue<int, vec<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        pq.push(k);
    }

    ll sum = 0;
    while (pq.size() > 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();

        sum += a + b;
        pq.push(a + b);
    }
    cout << sum << ln;
}
