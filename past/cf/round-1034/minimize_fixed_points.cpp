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

vector<int> getPrimesBelow(int n) {
    vector<bool> isPrime (n, true);
    for (int x = 2; x <= sqrt(n); x++) {
        if (isPrime[x]) {
            for (int i = x*x; i < n; i += x) {
                isPrime[i] = false;
            }
        }
    }
    vector<int> out;
    for (int x = n-1; x >= 2; x--) {
        if (isPrime[x])
            out.push_back(x);
    }
    return out;
}

void solve (int n) {
    vec<int> ans (n+1);
    vec<int> primes = getPrimesBelow(n+1);

    ans[1] = 1;
    int i = 0;
    while (i < primes.size() && 2*primes[i] > n) {
        ans[primes[i]] = primes[i];
        i++;
    }
    
    while (i < primes.size()) {
        vec<int> multiples;
        for (int j = 1; j * primes[i] <= n; j++) {
            if (ans[j * primes[i]] == 0)
                multiples.push_back(j * primes[i]);
        }
        // cout << multiples << endl;
        for (int j = 0; j < multiples.size(); j++) {
            ans[multiples[j]] = multiples[(j+1) % multiples.size()];
        }
        i++;
    }

    // print output
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << ln;
}

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        solve(k);
    }
}
