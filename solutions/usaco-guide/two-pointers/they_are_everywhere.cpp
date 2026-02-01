// https://codeforces.com/problemset/problem/701/C
// ironically i wanted to practice two pointers, but for my first two pointers problem i solved it using bin search
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

int toInt(char c) {
    if (isupper(c))
        return c - 'A';
    return c - 'a' + 26;
}

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n;
    string s;
    cin >> n >> s;

    vec<vec<int>> prefix (n+1, vec<int>(52, 0));
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i-1];
        prefix[i][toInt(s[i-1])]++;
    }
    
    auto complete = [&](int a, int b){
        // a and b are indexes in prefix array, inclusive
        for (int i = 0; i < 52; i++) {
            // if you need this pokemon and you don't have it
            if (prefix[n][i] > 0 && prefix[b][i] - prefix[a-1][i] == 0)
                return false;
        }
        return true;
    };

    auto firstTrue = [](int low, int high, function<bool(int)> f) {
        while (low < high) {
            int mid = (low+high) / 2;
            if (f(mid))
                high = mid;
            else
                low = mid + 1;
        }
        if (f(low)) return low;
        return -1;
    };

    int ans = 1e9;
    for (int i = 1; i <= n; i++) {
        int j = firstTrue(i, n, [&](int x){return complete(i, x);});
        if (j == -1) continue;
        ans = min(ans, j-i+1);
    }
    cout << ans << ln;
}
