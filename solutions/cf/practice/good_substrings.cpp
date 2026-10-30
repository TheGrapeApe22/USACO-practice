/*
https://codeforces.com/problemset/problem/2276/E
total substrings at i: (i+1) * (n-i)
construct "difference array" (reverse prefix sum)
first need nearest_2, nearest_0, nearest_5, nearest_6 arrays (nearest on the right)

example:
(only counting substrings that start at i=0. this process is repeated for each i)
     1 2 2 0 2 1 0 2 1 5 0 2 6
bad  3 3 3 3 3 3 3 3 3 3 2 1 0
bad1 3 0 0 0 0 0 0 0 0 0 -1 -1 -1
bad2 3 -3                -1       1

we construct bad2, and DOUBLE PREFIX SUM THAT BAD BOY!!
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

vi next_appearance_of_letter(char letter, string& s) {
    int n = (int)s.size();
    vi out (n);
    int curr = -1;
    for (int i = n-1; i >= 0; i--) {
        if (s[i] == letter)
            curr = i;
        out[i] = curr;
    }
    return out;
}

signed main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);

    int t; cin >> t;
    while (t--) {
        int n; string s;
        cin >> n >> s;
        vi next_2 = next_appearance_of_letter('2', s);
        vi next_0 = next_appearance_of_letter('0', s);
        vi next_5 = next_appearance_of_letter('5', s);
        vi next_6 = next_appearance_of_letter('6', s);
        
        vi bad (n, 0);
        for (int i = 0; i < n; i++) {
            int j = next_2[i];
            if (j == -1) break;
            j = next_0[j];
            if (j == -1) break;
            j = next_2[j];
            if (j == -1) break;
            // no bad substring if no 2025, or if 2026 before 2025
            int n5 = next_5[j], n6 = next_6[j];
            if (n6 == -1) n6 = n; // if no 2026, pretend the 6 is at the end
            if (n5 == -1 || (n6 < n5))
                continue;
            
            // if at this point, there is an n5 and it happens before n6
            bad[i] += n6 - n5;
            if (i+1 < n)
                bad[i+1] -= n6 - n5;
            
            if (n5+1 < n)
                bad[n5+1]--;
            if (n6+1 < n)
                bad[n6+1]++;
        }
        // DOUBLE PREFIX SUM THAT BAD BOY
        for (int i = 1; i < n; i++)
            bad[i] += bad[i-1];
        for (int i = 1; i < n; i++)
            bad[i] += bad[i-1];
        
        for (int i = 0; i < n; i++)
            cout << (i+1)*(n-i) - bad[i] << ' ';
        cout << ln;
    }
}
