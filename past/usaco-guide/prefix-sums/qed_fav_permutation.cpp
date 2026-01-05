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
template<typename T> ostream& operator<<(ostream& out, const set<T>& v) { print(v); return out; }
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

void solve(vec<int>& nums, vec<bool> str, int q, int n) {
    vec<bool> right (n, false);
    vec<bool> left (n, false);

    // construct left, right
    for (int i = 0; i < n;) {
        for (int j = i; j < nums[i]; j++)
            right[j] = true;
        i = max(i+1, nums[i]);
    }
    for (int i = n-1; i >= 0;) {
        for (int j = i; j > nums[i]; j--)
            left[j] = true;
        i = min(i-1, nums[i]);
    }
    // cout << right << left << "\n";
    vec<bool> cantLR (n, false);
    for (int i = 0; i < n; i++) {
        cantLR[i] = cantLR[i] || right[i];
    }
    for (int i = 0; i < n-1; i++) {
        cantLR[i] = cantLR[i] || left[i+1];
    }

    set<int> LRs;
    for (int i = 0; i < n-1; i++) {
        if (cantLR[i] && str[i] == 0 && str[i+1] == 1)
            LRs.insert(i);
    }
    // cout << cantLR << endl;
    // cout << LRs << endl;

    for (int q1 = 0; q1 < q; q1++) {
        int x; cin >> x;
        x--;
        str[x] = !str[x];

        if (cantLR[x-1] && str[x-1] == 0) {
            if (str[x] == 1)
                LRs.insert(x-1);
            else
                LRs.erase(x-1);
        }
        if (cantLR[x] && str[x+1] == 1) {
            if (str[x] == 1)
                LRs.erase(x);
            else
                LRs.insert(x);
        }

        // cout << left << endl;
        // cout << cantLR << endl;
        // cout << LRs << "\n";
        cout << (LRs.empty() ? "YES\n" : "NO\n");
    }
}

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, q;
        cin >> n >> q;
        vec<int> nums (n);
        for (int& x : nums) {
            cin >> x;
            x--;
        }
        
        string s; cin >> s;
        vec<bool> v (s.size());
        for (int i = 0; i < (int)s.size(); i++)
            v[i] = (s[i] == 'R');
        solve(nums, v, q, n);
    }
}
