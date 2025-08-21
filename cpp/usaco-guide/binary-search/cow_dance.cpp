#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1e9;
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
    // freopen("cowdance.in", "r", stdin);
    // freopen("cowdance.out", "w", stdout);
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n, x;
    cin >> n >> x;

    vec<int> d (n);
    for (int i = 0; i < n; i++)
        cin >> d[i];

    auto valid = [&](int k) {
        priority_queue<int, vec<int>, greater<int>> dancing;
        for (int i = 0; i < k; i++)
            dancing.push(d[i]);
        int t = 0;
        int i = k;
        while (!dancing.empty()) {
            while (!dancing.empty() && dancing.top() <= t) {
                if (i < n)
                    dancing.push(d[i++] + t);
                dancing.pop();
            }
            
            if (!dancing.empty())
                t = dancing.top();
        }
        // cout << k << " " << t << ln;
        return t <= x;
    };
    auto firstTrue = [](int low, int high, function<bool(int)> f) {
        while (low < high) {
            int mid = (low+high) / 2;
            if (f(mid))
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    };
    cout << firstTrue(1, n, valid) << ln;
}
