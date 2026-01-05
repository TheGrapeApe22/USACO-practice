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
    
    ll n, k;
    cin >> n >> k;

    vec<ll> v (n);
    for (ll i = 0; i < n; i++)
        cin >> v[i];
    
    auto possible = [&](ll maxSum) {
        ll sum = 0;
        ll count = 1;
        for (int i = 0; i < n; i++) {
            if (v[i] > maxSum) return false;

            if (sum + v[i] <= maxSum)
                sum += v[i];
            else {
                sum = v[i];
                count++;

                if (count > k)
                    return false;
            }
        }

        return count <= k;
    };

    cout << firstTrue(1, 1e15, possible) << ln;
}
