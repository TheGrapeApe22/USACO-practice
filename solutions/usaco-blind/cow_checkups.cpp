// https://usaco.org/index.php?page=viewproblem2&cpid=1469
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

/*
pick (l, r) where r = l or l+1 (O(n))
    count the number of matches
    for each expansion (l-k, r+k):
        edit count
        edit ans
*/

/*
count the number of i's that have cows[i] == preference[i]
ans[ogCount] += n
for l in (0...n-1), r in (l, l+1):
    make sure l and r are in bounds, else break
    count = ogCount
    for k = (0,1,2,...)
        break if out of bounds
        if l==r and k==0, continue
        count-- if cow == preference at [l-k]
        count-- if cow == preference at [r+k], but don't double subtract for l==r
        count++ if cow[l-k] == preference[r+k]
        count++ if cow[r+k] == preference[l-k]
        ans[count]++
*/

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n;
    cin >> n;

    vec<int> cows (n), pref (n);
    for (int& x : cows) cin >> x;
    for (int& x : pref) cin >> x;

    vec<int> ans (n+1);

    int ogCount = 0;
    for (int i = 0; i < n; i++) {
        if (cows[i] == pref[i])
            ogCount++;
    }
    ans[ogCount]+= n;

    for (int l = 0; l < n; l++) {
        for (int r = l; r <= l+1; r++) {
            if (l < 0 || r >= n) continue;
            int count = ogCount;
            for (int k = 0; l-k >= 0 && r+k < n; k++) {
                if (l==r && k==0) continue;
                if (cows[l-k] == pref[l-k]) count--;
                if (cows[r+k] == pref[r+k] && l-k != r+k) count--;
                if (cows[l-k] == pref[r+k]) count++;
                if (cows[r+k] == pref[l-k]) count++;
                ans[count]++;
                // cout << l-k _ r+k _ count << ln;
            }
        }
    }

    for (int x : ans) cout << x << ln;
}
