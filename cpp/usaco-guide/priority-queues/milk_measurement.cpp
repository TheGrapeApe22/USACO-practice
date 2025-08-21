/*
sort inputs by day

amtOfCow<cow, amt>

map<amt, count> count
amounts[0] = 1

for each measurement:
    int day, cow, change
    oldAmt = amtOfCow[cow]
    newAmt = oldAmt + change
    oldHighest = amounts.highest

    amtOfCow[cow] = newAmt
    
    if oldAmt != 0
        amounts.[oldAmt]--
    amounts[newAmt]++
    newHighest = amounts.highest
    
    // if amounts.highest changed
    if (newAmt == newHighest && amounts[newHighest] > 1)
        count
    
    if (oldAmt == oldHighest && newAmt != newHighest)
        count
    if (oldAmt != oldHighest && newAmt == newHighest)
        count
*/

#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    // freopen("measurement.in", "r", stdin);
    // freopen("measurement.out", "w", stdout);
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n, g;
    cin >> n >> g;

    // day, cow, change
    vec<vec<int>> measurements (n, vec<int> (3));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++)
            cin >> measurements[i][j];
    }
    sort(all(measurements));
    
    // amtOfCow[cow] = amt
    map<int, int> amtOfCow;
    map<int, int> amounts;
    amounts[0] = 2;

    int count = 0;
    for (auto& m : measurements) {
        int cow = m[1], change = m[2];
        int oldAmt = 0;
        if (amtOfCow.count(cow))
            oldAmt = amtOfCow[cow];
        int newAmt = oldAmt + change;
        int oldHighest = (*amounts.rbegin()).first;
        int oldNumDisplayed = amounts[oldHighest];

        amtOfCow[cow] = newAmt;
        if (oldAmt != 0) {
            amounts[oldAmt]--;
            if (amounts[oldAmt] == 0)
                amounts.erase(oldAmt);
        }
        amounts[newAmt]++;

        int newHighest = (*amounts.rbegin()).first;

        bool increment = 0;
        // if amounts.highest changed
        if (oldNumDisplayed != amounts[newHighest])
            increment = 1;
        if (oldAmt == oldHighest && newAmt != newHighest)
            increment = 1;
        else if (oldAmt != oldHighest && newAmt == newHighest)
            increment = 1;
        
        count += increment;
        
        // cout << amtOfCow << ln;
    }
    cout << count << ln;
}
