/*
https://usaco.org/index.php?page=viewproblem2&cpid=1350
OMGG IT'S A DP PROBLEM?? IN SILVER?? NO WAY

arrays: weights (input, constant), acrobats (dp)
fill(x, count):
    bin search to find index of first number >=x
    fill acrobats forward until count is depleted or acrobats is maximized

fill(-67, M)
iterate i:
    fill i+k, acrobats[i]
*/

/*
mistakes:
 - bad variable naming, had to fix like 5 names
 - failed to consider critical TLE test case because my worst case was O(n^2)

wow. the intended solution was to use a queue. i am both amazed and disappointed in myself.
*/


#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define _ << " " <<
#define all(x) (x).begin(), (x).end()
#define int long long
using namespace std; using ll = long long; using pii = pair<int, int>; using vi = vector<int>;
template<typename T> ostream& operator<<(ostream& out, const vector<T>& v) {
    cout << "["; for (size_t i = 0; i+1 < v.size(); i++) cout << v[i] << ", "; cout << *v.rbegin() << "]"; return out;
}

struct weight {
    int val, num_cows, num_acrobats = 0;

    bool operator< (weight& other) { return this->val < other.val; }
};

void fill(int x, int count, vec<weight>& weights) {
    // find first number >= x
    int n = weights.size();
    int low = 0, high = n; // [low, high)
    while (low < high) {
        int mid = (low+high)/2;
        if (weights[mid].val >= x)
            high = mid;
        else
            low = mid+1;
    }
    if (low >= n)
        return;
    
    weights[low].num_acrobats += count;
}

signed main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n, m, k;
    cin >> n >> m >> k;

    vec<weight> weights (n);
    for (weight& w : weights) {
        cin >> w.val >> w.num_cows;
    }
    sort(all(weights));
    
    fill(-67, m, weights);

    // for (auto& x : weights)
    //     cout << x.val _ x.num_cows _ x.num_acrobats << ln;

    int total = 0;
    for (int i = 0; i < n; i++) {
        weight& w = weights[i];
        int overflow = w.num_acrobats - w.num_cows;
        if (overflow > 0) {
            if (i+1 < n)
                weights[i+1].num_acrobats += overflow;
            w.num_acrobats -= overflow;
        }
        total += weights[i].num_acrobats;
        fill(weights[i].val + k, weights[i].num_acrobats, weights);
    }

    // for (auto& x : weights)
    //     cout << x.val _ x.num_cows _ x.num_acrobats << ln;

    cout << total << endl;
}
