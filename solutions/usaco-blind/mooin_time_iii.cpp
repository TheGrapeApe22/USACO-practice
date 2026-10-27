/*
https://usaco.org/index.php?page=viewproblem2&cpid=1517

this had a satisfying Eureka moment :D
NEAREST NEIGHBOR ARRAYS!!!!

construct nearest letter arrays
    arrays: left, right
    for each letter
        curr = -1
        for i in string
            if i = letter
                curr = i
            left[letter][i] = etc
            etc
for each query, test every combination of two letters
    l, r are query inputs
    min = 6766767676767
    for each letter (a, b)
        i = right[a][l]
        k = left[b][r]
        j1 = left[b][(i+k+1)/2]
        j2 = right[b][(i+k)/2]
        j = the one closest to (i+k)/2

        calc area
*/

/*
mistakes:
* did i++ instead of i-- on a backwards loop
* averaged i+k instead of i+j, reading from an unused variable
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

int solve(vec<vi>& left, vec<vi>& right) {
    int l, r;
    cin >> l >> r;
    l--; r--;
    int largest_area = -1;
    for (int a = 0; a < 26; a++) {
        for (int b = 0; b < 26; b++) {
            if (a == b) continue;
            int i = right[a][l], k = left[b][r];
            if (i == -1 || k == -1 || i > k) continue;
            /*k = left[b][r]
            j1 = left[b][(i+k+1)/2]
            j2 = right[b][(i+k)/2]
            j = the one closest to (i+k)/2*/
            int j1 = left[b][(i+k+1)/2];
            int j2 = right[b][(i+k)/2];
            int j;
            if (j2 == -1 || abs(j1*2 - (i+k)) < abs(j2*2 - (i+k)))
                j = j1;
            else
                j = j2;

            if (j == -1 || j <= i || j >= k) continue;

            // cout << (char)(a+'a') _ (char)(b+'a') _ i _ j _ k _ (j-i)*(k-j) <<endl;
            largest_area = max(largest_area, (j-i)*(k-j));
        }
    }
    return largest_area;
}

signed main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n, q; string s;
    cin >> n >> q >> s;

    vec<vi> left(26, vi(n)), right(26, vi(n));
    
    for (char a = 'a'; a <= 'z'; a++) {
        int curr = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == a)
                curr = i;
            left[a - 'a'][i] = curr;
        }

        curr = -1;
        for (int i = n-1; i >= 0; i--) {
            if (s[i] == a)
                curr = i;
            right[a - 'a'][i] = curr;
        }
    }

    for (int qq = 0; qq < q; qq++)
        cout << solve(left, right) << ln;
}
