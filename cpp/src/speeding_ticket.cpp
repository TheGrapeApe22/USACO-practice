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

int main() {
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;

    vec<pii> road (n);
    vec<pii> car (m);
    for (auto& p : road)
        cin >> p.first >> p.second;
    for (auto& p : car)
        cin >> p.first >> p.second;

    int overLimit = 0;
    int i = 0, j = 0;
    while (i < n) {
        overLimit = max(overLimit, car[j].second - road[i].second);
        // cout << overLimit _ i _ j << ln;

        int travel = min(road[i].first, car[j].first);
        road[i].first -= travel;
        car[j].first -= travel;
        if (road[i].first == 0) i++;
        if (car[j].first == 0) j++;
    }

    cout << overLimit << ln;
}
