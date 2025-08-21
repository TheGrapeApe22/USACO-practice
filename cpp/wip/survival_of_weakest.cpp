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
ll MOD = 1e9+7;

void solve (vec<ll>& nums) {
    ll n = nums.size();
    if (n == 1) {
        cout << nums[0] << endl;
        return;
    }

    vec<ll> out;
    priority_queue<vec<ll>, vec<vec<ll>>, greater<vec<ll>>> pq;
    
    auto push = [&](ll a, ll b) {
        if (a == b) return;
        if (a >= n || b >= n) return;

        // cout << a << " " << b << ln;
        pq.push({(nums[a] + nums[b])%MOD, a, b});
    };

    push(0, 1);
    
    for (ll i = 0; i < n - 1; i++) {
        vec<ll> curr = pq.top();
        out.push_back(curr[0]);
        pq.pop();

        push(curr[1]+1, curr[2]);
        push(curr[1], curr[2]+1);
    }
    solve(out);
}

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    ll n;
    cin >> n;

    vec<ll> nums (n);
    for (ll i = 0; i < n; i++)
        cin >> nums[i];
    sort(all(nums));
    solve(nums);
}
