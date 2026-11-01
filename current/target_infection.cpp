/*
https://codeforces.com/problemset/problem/2271/D


helper function sum(l, r)
    setup:
        prefix sum, vector of pairs {index, val, start or end (bool)}
    bin search to find the leftmost and rightmost thing in [l, r] -> a, b
    total = prefix[b].val - prefix[a].val
    if prefix[b] is a start, total += b - prefix[b].index
    if prefix[a] is an end, total -= prefix[a].index - a

find overflow
offset = amount overflowed
binsearch to move to the nearest [offset] number of blanks
*/

#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define _ << " " <<
#define all(x) (x).begin(), (x).end()
#define int long long
using namespace std; using ll = long long; using pii = pair<int, int>; using vi = vector<int>;
namespace {
    template<typename it> void print(it, it);
    template<typename T> void print(T& v) {print(v.begin(), v.end());}
    template<typename T, typename U> ostream& operator<<(ostream& out, pair<T, U> p) {
        cout << "(" << p.first << ", " << p.second << ")"; return out;
    }
    template<typename T> ostream& operator<<(ostream& out, const vector<T>& v)             { print(v); return out; }
    template<typename T> ostream& operator<<(ostream& out, const set<T>& v)                { print(v); return out; }
    template<typename T> ostream& operator<<(ostream& out, const multiset<T>& v)           { print(v); return out; }
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

auto firstTrue = [](int low, int high, function<bool(int)> f) {
    int ogHigh = high;
    while (low < high) {
        int mid = (low+high) / 2;
        if (f(mid))
            high = mid;
        else
            low = mid + 1;
    }
    if (low < ogHigh && f(low)) return low;
    return -1LL;
};

auto lastTrue = [](int low, int high, function<bool(int)> f) {
    int ogHigh = high;
    while (low < high) {
        int mid = (low+high+1) / 2;
        // cout << low _ high << endl;
        if (mid < ogHigh && f(mid))
            low = mid;
        else
            high = mid - 1;
    }
    if (f(low)) return low;
    return -1LL;
};

vec<pair<pii, bool>> prefix;

#define INDEX first.first
#define VAL first.second

int sum(int l, int r) {
    l--;
    int a = lastTrue(0, prefix.size(), [&](int i) -> bool { return prefix[i].INDEX <= l; });
    int b = lastTrue(0, prefix.size(), [&](int i) -> bool { return prefix[i].INDEX <= r; });
    // cout _ prefix[a] _ prefix[b] << endl;
    if (a == -1)
        return 0;
    
    int left_prefix, right_prefix;
    if (prefix[a].second == 0)
        left_prefix = prefix[a].VAL + l - prefix[a].INDEX;
    else
        left_prefix = prefix[a].VAL;
    
    if (prefix[b].second == 0)
        right_prefix = prefix[b].VAL + r - prefix[b].INDEX;
    else
        right_prefix = prefix[b].VAL;
    
    return right_prefix - left_prefix;
}

signed main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int t; cin >> t;
    while (t--) {
        int n, num_people, infections_needed;
        cin >> n >> num_people >> infections_needed;

        vi ends;

        prefix = {{{0, 0}, 1}};
        int total = 0;
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            prefix.push_back({{a, total+1}, 0});
            total += b-a+1;
            prefix.push_back({{b, total}, 1});
            ends.push_back(b);
        }


        // cout << prefix << endl;
        // cout << sum(1, 13) _ ends[<< endl;

        int ans = -1;
        for (int i = n - 1; i >= 0; i--) {
            // cout << i << endl;
            if (ends[i] - num_people < 0)
                break;
            int s = sum(ends[i] - num_people+1, ends[i]);
            // cout _ ends[i] - num_people+1 _ ends[i] _ s << endl;
            if (s >= infections_needed) {
                cout << ends[i] - sum(1, ends[i]) + s - infections_needed<<endl;
                ans = firstTrue(ends[i], 100, [&](int j) -> bool {
                    // cout << j << endl;
                    return j - sum(1, j) >= ends[i] - sum(1, ends[i]) + s - infections_needed;
                }) - num_people + 1;

                break;
            }
        }
        cout << ans << ln;
    }
}
