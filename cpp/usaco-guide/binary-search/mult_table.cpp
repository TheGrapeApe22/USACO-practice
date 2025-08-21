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

ll firstTrue(ll low, ll high, function<bool(ll)> f) {
    while (low < high) {
        ll mid = (low+high) / 2;
        if (f(mid))
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    ll n;
    cin >> n;

    // count the number of integers <= x
    auto count = [&](ll x) {
        ll out = 0;
        for (ll i = 1; i <= n; i++)
            out += min(n, x/i);
        return out;
    };

    auto rightHalf = [&](ll x) {
        return count(x)-1 >= n*n/2;
    };

    // cout << count(6) << " ";
    
    cout << firstTrue(1, n*n, rightHalf) << ln;

    // multiset<int> st;
    // for (int i = 1; i <= 5; i++) {
    //     for (int j = 1; j <= 5; j++) {
    //         st.insert(i*j);
    //     }
    // }
    // cout << st << ln;
}
