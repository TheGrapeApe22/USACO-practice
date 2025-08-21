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
    
    ll n, q;
    cin >> n >> q;

    vec<ll> v (n);
    for (ll &x : v)
        cin >> x;
    
    sort(all(v), greater<ll>());
    
    vec<ll> count (n);
    for (ll i = 0; i < q; i++) {
        ll a, b;
        cin >> a >> b;
        a--; b--;

        count[a]++;
        if (b+1 < n)
            count[b+1]--;
    }

    for (ll i = 1; i < n; i++)
        count[i] += count[i-1];

    sort(all(count), greater<ll>());
    
    ll sum = 0;
    for (ll i = 0; i < n; i++) {
        sum += count[i] * v[i];
    }
    cout << sum << "\n";
}
