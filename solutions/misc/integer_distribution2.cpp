/*
dp(mask) = dp(mask^(1<<a)^(1<<b) + nums[a]^nums[b])
    where ath bit and bth bit are both 1

order of operations, WHY DOES ADDITION TAKE PRECEDENCE OVER XOR
took 20 minutes to debug
*/

#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
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

const ll INF = (ll)1e18;

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    ll n;
    cin >> n;
    vec<ll> nums (n);
    for (ll i = 0; i < n; i++) {
        cin >> nums[n - i - 1];
    }

    vec<ll> dp ((1<<n), -1);
    dp[0] = 0;

    function<ll(ll)> solve = [&](ll mask) {
        if (dp[mask] != -1) return dp[mask];
        
        for (ll a = 0; a < n; a++) {
            if (!((mask>>a) & 1)) continue;
            for (ll b = 0; b < a; b++) {
                if (!((mask>>b) & 1)) continue;
                dp[mask] = max(dp[mask], solve(mask^(1<<a)^(1<<b)) + (nums[a]^nums[b]));
            }
        }
        if (dp[mask] == -1)
            dp[mask] = -INF;
        return dp[mask];
    };

    vec<ll> dp2 ((1<<n), -1);
    dp2[0] = 0;

    function<ll(ll)> solve2 = [&](ll mask) {
        if (dp2[mask] != -1) return dp2[mask];
        
        for (ll a = 0; a < n; a++) {
            if (!((mask>>a) & 1)) continue;
            for (ll b = 0; b < a; b++) {
                if (!((mask>>b) & 1)) continue;
                ll ans = solve2(mask^(1<<a)^(1<<b)) + (nums[a]^nums[b]);
                dp2[mask] = min(dp2[mask], ans);
                if (dp2[mask] == -1) dp2[mask] = ans;
            }
        }
        if (dp2[mask] == -1)
            dp2[mask] = INF;
        return dp2[mask];
    };
    
    cout << solve2((1<<n) - 1) << " " << solve((1<<n) - 1) << ln;
    // cout << dp2 << ln;
}
