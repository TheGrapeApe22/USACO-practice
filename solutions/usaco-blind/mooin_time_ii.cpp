// https://usaco.org/index.php?page=viewproblem2&cpid=1468
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
iterate backwards [i]
if arr[i] has been seen before to the right:
    count += number of distinct things before i, excluding 4
*/

int main() {
    #define int long long
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n;
    cin >> n;

    vec<int> arr (n);
    vec<int> freq_left (1e6+1);
    int count_left = 0;
    
    // construct freq_left from arr
    for (int& x : arr) {
        cin >> x;
        if (freq_left[x] == 0) count_left++;
        freq_left[x]++;
    }
    
    // iterate backwards [i]
    int ans = 0;
    vec<bool> done_moo (1e6+1);
    vec<bool> exists_right (n);
    
    for (int i = n-1; i > 0; i--) {
        // freq_left[i]--, update count.
        freq_left[arr[i]]--;
        if (freq_left[arr[i]] == 0) count_left--;
        // check if done moo
        if (done_moo[arr[i]]) continue;
        // if arr[i] has been seen before to the right:
        if (exists_right[arr[i]]) {
            // count += number of distinct things before i, excluding arr[i]
            // that number is count, -1 if arr[i] in freq_left
            ans += count_left;
            if (freq_left[arr[i]] > 0) ans--;
            // done moo
            done_moo[arr[i]] = true;
        }
        // arr[i] has been seen now
        exists_right[arr[i]] = true;
    }
    cout << ans << ln;
}
