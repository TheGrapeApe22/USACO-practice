/*
https://usaco.org/index.php?page=viewproblem2&cpid=1255

"L 1" = lose in 1 turn, i.e. on your turn you lose
"W 2" = win in 2 moves, i.e. i move, then opp loses on their turn

0 L 1
1 W 2
2 W 2
3 W 2
4 L 3
5 W 2
6 W 4
7 W 2
8 L 5
9 W 4
10 W 6
11 W 2
12
13 W 2
14
15 W 4
16
17 W 2
18
19 W 2
20
21 W 4
22

terrible stupid frustrating life-draining observation: L only on 4n, and time is all increasing odd numbers


damn. i checked the solution. the strat was not to cache everything, because turns out the number of losses would be n/4, not sqrt(n). my entire solution wasn't going to work and i had to make that (mod 4) observation.

RIP
*/

#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define _ << " " <<
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
// #define int long long
using namespace std; using ll = long long; using pii = pair<int, int>;
template<typename T> ostream& operator<<(ostream& out, const vector<T>& v) {
    cout << "["; for (size_t i = 0; i+1 < v.size(); i++) cout << v[i] << ", "; cout << *v.rbegin() << "]"; return out;
}

int N = (int)5e6;

signed main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    vec<pair<char, int>> results(N + 1, {'_', 1e9});
    vec<int> legal_moves = {1};
    vec<bool> is_prime (N+1, true);

    // use sieve's to mark composites as U (unknown)
    for (int x = 2; x <= N; x++) {
        if (is_prime[x]) {
            legal_moves.push_back(x);
            for (int y = 2*x; y <= N; y+=x)
                is_prime[y] = false;
        }
    }

    cout << legal_moves.size() << endl;

    // mark losses
    for (int x = 0; x < results.size(); x++) {
        auto& curr = results[x];
        if (curr.F == '_') {
            // curr is a loss. look for the previous win with the longest time possible
            int max_win_time = 0;
            for (int y : legal_moves) {
                if (x - y <= 0) break;
                max_win_time = max(max_win_time, results[x - y].S);
            }
            curr = {'L', max_win_time + 1};

            for (int y : legal_moves) {
                if (x + y >= results.size()) break;
                results[x+y] = {'W', min(results[x+y].S, curr.S + 1)};
            }
        }
    }

    for (int i = 0; i < 100; i++) {
        cout << i _ results[i].F _ results[i].S << ln;
    }
}
