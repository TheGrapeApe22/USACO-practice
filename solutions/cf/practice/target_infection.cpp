/*
https://codeforces.com/problemset/problem/2271/D (1700 rating)
this was a really good problem. i learned a lot from my 5 billion mistakes, including that i have to be more patient XD

helper function sum(l, r)
find overflow
binsearch to find nearby non-overflow
*/

/*
mistakes:
THIS WAS SO FREAKING TERRIBLE.
* my original solution of counting blanks straight up didn't work
* my second solution of binsearching (checking ends instead of starts) sucked due to edge cases
* i forgot how to use my own binsearch functions, putting (0, n) instead of (0, n-1).
* forgot how prefix sums work; they require prefix[b] - prefix[a-1]
* failed to consider edge case of x<1 due to the a-1 thing

had to check test case failures multiple times instead of unit testing myself. :(
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
    while (low < high) {
        int mid = (low+high) / 2;
        if (f(mid))
            high = mid;
        else
            low = mid + 1;
    }
    if (f(low)) return low;
    return -1LL;
};

auto lastTrue = [](int low, int high, function<bool(int)> f) {
    while (low < high) {
        int mid = (low+high+1) / 2;
        if (f(mid))
            low = mid;
        else
            high = mid - 1;
    }
    if (f(low)) return low;
    return -1LL;
};

vec<pair<pii, bool>> prefix;
int n, num_people, infections_needed;

#define INDEX first.first
#define VAL first.second
int sum_at(int l) {
    int r = l + num_people - 1;
    l--;
    
    int a = lastTrue(0, prefix.size() - 1, [&](int i) -> bool { return prefix[i].INDEX <= l; });
    int b = lastTrue(0, prefix.size() - 1, [&](int i) -> bool { return prefix[i].INDEX <= r; });
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
        cin >> n >> num_people >> infections_needed;

        vi starts;

        prefix = {{{-1, 0}, 1}};
        
        int total = 0;
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            starts.push_back(a);
            
            prefix.push_back({{a, total+1}, 0});
            total += b-a+1;
            prefix.push_back({{b, total}, 1});
        }

        int ans = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (sum_at(starts[i]) >= infections_needed) {
                int right_bound = 1e18;
                if (i < n-1)
                    right_bound = starts[i+1] - 1;

                ans = firstTrue(starts[i], right_bound, [&](int x) -> bool {
                    return sum_at(x) <= infections_needed;
                });

                if (ans != -1)
                    break;
            }
        }
        cout << ans << ln;
    }
}
