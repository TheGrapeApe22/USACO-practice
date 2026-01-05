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
    int n, t, k;
    cin >> n >> t >> k;

    int low = 0, high = n-1;
    int countLeft = 0;

    while (low < high) {
        int mid = (low + high) / 2;
        cout << "? " << low+1 << " " << mid+1 << endl;

        int x; cin >> x;
        
        // number of zeros
        x = (mid-low+1) - x;
        // cout << x << endl;

        if (countLeft + x < k) {
            countLeft += x;
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    cout << "! " << low+1 << endl;
    exit(0);
}
