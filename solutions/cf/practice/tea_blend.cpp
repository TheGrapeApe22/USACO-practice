/*
https://codeforces.com/problemset/problem/2275/F

i love python, i can literally just do this lol

from sympy.ntheory import divisor_count
for i in range(100):
    if (divisor_count(i) % 2):
        print(i)
which only prints perfect squares >:P

obs: 2*3*5*7*11*13*17 = ~500,000
so every number can have at most 7 prime factors!

MY SOLUTION:
only store prime factors with odd exponents. so
12 3 5 45 1 7 63 2
becomes
[3] [3] [5] [5] [] [7] [7] [2]

for each j, use freq[] to calculate number of i's that work.

* oof. memory limit exceeded. tried switching from ll to int lmao.
* had to AI this. it was because freq[...] creates a new entry if doesn't exist, and that was clogging it up.
* had to AI again because TLE. DAMN, it literally added 1 line (65) which is so freaking smart because it means i don't have to check primes greater than sqrt(10^6). because it can't have two prime factors greater than 1000!! EUREKA. damn. that would have been hard to come up with on my own. cool problem.
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

int MAX_PRIME = 1e3;
vec<bool> is_prime (MAX_PRIME, true);
vi primes;

set<int> reduce(int x) {
    set<int> out;
    for (int p : primes) {
        int exp = 0;
        while (x % p == 0) {
            x /= p;
            exp++;
        }
        if (exp % 2 == 1)
            out.insert(p);
    }
    if (x > 1)
        out.insert(x);
    return out;
}

signed main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    for (int x = 2; x < MAX_PRIME; x++) {
        if (!is_prime[x]) continue;
        primes.push_back(x);
        for (int y = 2*x; y < MAX_PRIME; y+=x)
            is_prime[y] = false;
    }

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vec<set<int>> factors (n);
        map<set<int>, int> freq;

        for (auto& s : factors) {
            int x; cin >> x;
            s = reduce(x);
            freq[s]++;
        }

        int total = 0;
        set<int> curr = {};
        for (int i = 0; i < n; i++) {
            for (int x : factors[i]) {
                auto existing_x = curr.find(x);
                if (existing_x == curr.end())
                    curr.insert(x);
                else
                    curr.erase(existing_x);
            }
            // cout << curr << ln;
            if (freq.find(curr) != freq.end())
                total += freq[curr];
        }

        // cout << factors << ln;
        cout << total << ln;
    }
}
