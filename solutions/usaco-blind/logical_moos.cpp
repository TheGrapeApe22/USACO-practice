/*
https://usaco.org/index.php?page=viewproblem2&cpid=1419
huge AI hint: "nearest neighbor arrays"

T or (F and T and F) or (F and T) or F

* can the selected [and] block be turned true?
    * nearest [and F] happens before nearest [or], both sides?
* can whole thing be false?
    * farthers [or [true]] happens after nearest [or], both sides?
*/


#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define _ << " " <<
#define all(x) (x).begin(), (x).end()
// #define int long long
using namespace std; using ll = long long; using pii = pair<int, int>;
template<typename T> ostream& operator<<(ostream& out, const vector<T>& v) {
    cout << "["; for (size_t i = 0; i+1 < v.size(); i++) cout << v[i] << ", "; cout << *v.rbegin() << "]"; return out;
}

signed main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n, q;
    cin >> n >> q;
    vec<string> statement (n);
    for (string& x : statement)
        cin >> x;
    
    int leftmost_Tor = 1e9;
    int rightmost_orT = -1;

    bool curr_and_block = true;
    int start_of_and_block = 0;
    for (int i = 0; i < n; i+=2) {
        curr_and_block &= (statement[i] == "true");
        // check if [and block] is ending
        if ((i == n-1 || statement[i+1] == "or")) {
            if (curr_and_block)
                rightmost_orT = start_of_and_block;
            curr_and_block = true;
            start_of_and_block = i+2;
        }
    }

    curr_and_block = true;
    start_of_and_block = n-1;
    for (int i = n-1; i >= 0; i-=2) {
        curr_and_block &= (statement[i] == "true");
        // check if [and block] is ending
        if ((i == 0 || statement[i-1] == "or")) {
            if (curr_and_block)
                leftmost_Tor = start_of_and_block;
            curr_and_block = true;
            start_of_and_block = i-2;
        }
    }

    vec<int> nearest_f_right (n, -1);
    vec<int> nearest_or_right (n, -1);
    int curr_nearest_f = -1, curr_nearest_or = -1;
    for (int i = n-1; i >= 0; i-=2) {
        if (i+1 < n && statement[i+1] == "or")
            curr_nearest_or = i+1;
        nearest_or_right[i] = curr_nearest_or;
        

        nearest_f_right[i] = curr_nearest_f;
        if (statement[i] == "false")
            curr_nearest_f = i;
    }

    vec<int> nearest_f_left (n, -1);
    vec<int> nearest_or_left (n, -1);
    curr_nearest_f = -1, curr_nearest_or = -1;
    for (int i = 0; i < n; i+=2) {
        if (i > 0 && statement[i-1] == "or")
            curr_nearest_or = i-1;
        nearest_or_left[i] = curr_nearest_or;

        nearest_f_left[i] = curr_nearest_f;
        if (statement[i] == "false")
            curr_nearest_f = i;
    }
    // cout << nearest_or_right << ln;

    for (int q1 = 0; q1 < q; q1++) {
        int a, b; string c;
        cin >> a >> b >> c;
        a--; b--;
        
        if (c == "true") {
            // [selected [and block] can be turned true] or [there is another [or true]]
            bool one = (nearest_or_right[b] != -1 && nearest_f_right[b] > nearest_or_right[b] || nearest_f_right[b] == -1) && (nearest_f_left[a] < nearest_or_left[a] || nearest_f_left[a] == -1);

            bool two = (rightmost_orT > b || leftmost_Tor < a);

            // cout << nearest_f_right[b] _ nearest_or_right[b] _ nearest_f_left[a] _ nearest_or_left[a]<< ln;

            if (one || two) cout << "Y";
            else cout << "N";
        }
        else {
            // farthest [or [true]] happens before nearest or, both sides
            if (leftmost_Tor >= a && rightmost_orT <= b)
                cout << "Y";
            else cout << "N";
        }
    }
    cout << ln;
}
