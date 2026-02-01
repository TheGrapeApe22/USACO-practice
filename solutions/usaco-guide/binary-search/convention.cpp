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
    // freopen("convention.in", "r", stdin);
    // freopen("convention.out", "w", stdout);
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    // cows, buses, cows per bus
    int n, m, c;
    cin >> n >> m >> c;

    vec<int> times (n);
    for (int i = 0; i < n; i++)
        cin >> times[i];
    
    sort(all(times));

    auto valid = [&](int maxWait){
        int count = 1;
        int currStart = times[0];
        int currCows = 1;
        for (int i = 1; i < n; i++) {
            if (currCows >= c || times[i] - currStart > maxWait) {
                currStart = times[i];
                count++;
                currCows = 0;
            }
            currCows++;
        }
        return count <= m;
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

    cout << firstTrue(0, times[n-1] - times[0], valid) << ln;
}
