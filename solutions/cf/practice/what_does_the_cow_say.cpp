/*
https://codeforces.com/problemset/problem/2261/E
*1800

(()())()
12121010 (prefix_both)
00112334 (prefix_close)
construct these two arrays

construct all_indexes array of prefix_both
0: 5, 7
1: 0, 2, 4
2: 1, 3

better sol:
for each i at an open parenth:
    ans = biggest item in prefix_both between l and n such that prefix_close at ans <= prefix_close[i]+k
        x is between prefix_both[i] and 1e6
        to check if x works:
            let j be the index of x in prefix_both
            find largest j such that prefix_close[all_indexes[x][j]] <= prefix_close[i]+k
            check if all_indexes[j] >= i
        if l == 0, add prefix_close[all_indexes[x][j]] to x

12 4
((()())())()
123232121010
000112334556
l       r

3: 2, 4

mistakes:
* mixed up prefix_both with prefix_close like three times
* missed edge case where removing things on the right adds to the left

LET'S GOOOO I BUILT THIS TOP DOWN AND IT WORKED FIRST TRY YESSSS
(much credit to the many test cases, i have no idea how i passed so many of them when i had literally the wrong variables. anyway.)

after checkign tutorial:
* BRUHHH IT WAS SOLVABLE IN O(n) WITH A DEQUE NOOOO I'M SO BLIND
* why is there a trees tag with DFS? woahh. that is quite insane. glad that wasn't the only sol.
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

int lastTrue(int low, int high, function<bool(int)> f) {
    while (low < high) {
        int mid = (low+high+1)/2;
        if (f(mid))
            low = mid;
        else
            high = mid-1;
    }
    if (f(low))
        return low;
    return -1;
}

signed main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int t; cin >> t;
    while (t--) {
        int n, k; string s;
        cin >> n >> k >> s;

        vi prefix_close (n), prefix_both (n);

        prefix_both[0] = 1;
        for (int i = 1; i < n; i++) {
            prefix_both[i] = prefix_both[i-1] + ((s[i] == '(') ? 1 : -1);
            prefix_close[i] = prefix_close[i-1] + ((s[i] == ')') ? 1 : 0);
        }

        unordered_map<int, vi> all_indexes;
        for (int i = 0; i < n; i++) {
            all_indexes[prefix_both[i]].push_back(i);
        }

        // cout << prefix_both << endl;
        // cout << prefix_close << endl;

        int best = 0;
        for (int i = 0; i < n;) {
            int location_of_ans = -1;
            int ans = lastTrue(prefix_both[i], 1e6, [&](int x) {
                auto it = all_indexes.find(x);
                if (it == all_indexes.end())
                    return false;
                vi& indexes = (*it).second;
                
                int search = lastTrue(0, indexes.size()-1, [&](int j) {
                    // holy nested BSearch.
                    return prefix_close[indexes[j]] <= prefix_close[i] + k;
                });
                if (search == -1) return false;

                location_of_ans = indexes[search];
                return indexes[search] >= i;
            }) - prefix_both[i] + 1;
            
            if (i == 0) {
                int count = 0;
                for (int j = location_of_ans+1; j < n; j++) {
                    if (s[j] == '(')
                        count++;
                }
                ans += min(prefix_close[location_of_ans] + count, k);
            }
            
            best = max(best, ans);

            // find next '('
            i++;
            while (i < n && s[i] != '(') i++;
        }
        cout << best << ln;
    }
}
