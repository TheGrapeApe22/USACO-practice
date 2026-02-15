// https://usaco.org/index.php?page=viewproblem&cpid=1551
// solved with 3:47:00 left
#include <bits/stdc++.h>
#define ln "\n"
using namespace std;

/*
iterate og right to left
    nextChar = og[i]
    if (o_counter is odd)
        flip nextChar
    
    if nextChar is O
        o_counter++
*/

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int t, k;
    cin >> t >> k;

    for (int t1 = 0; t1 < t; t1++) {
        cout << "YES\n";
        if (k == 0) continue;
        int n; string s;
        cin >> n >> s;

        string ans;
        bool o_counter = 0;
        for (int i = n-1; i >= 0; i--) {
            int nextChar = s[i];
            if (o_counter) {
                if (nextChar == 'O') nextChar = 'M';
                else nextChar = 'O';
            }
            if (nextChar == 'O')
                o_counter = !o_counter;
            
            ans += nextChar;
        }
        for (int i = n-1; i >= 0; i--) {
            cout << string {ans[i]};
        }
        cout << ln;
    }
}
