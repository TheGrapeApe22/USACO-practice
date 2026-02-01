// https://codeforces.com/contest/371/problem/C
// mistake: integer overflow with upper bound at 1e18
#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define _ << " " <<
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using pii = pair<int, int>;
/*
(bin search on x)
is it possible to make x hamburgers?
calc number of ingredients needed
calc cost of ingredients
*/
int main() {
    #define int long long
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    string s; cin >> s;
    vec<int> recipe(3), have(3), price(3);
    for (char c : s) {
        if (c == 'B') recipe[0]++;
        else if (c == 'S') recipe[1]++;
        else if (c == 'C') recipe[2]++;
    }
    for (int& a : have) cin >> a;
    for (int& a : price) cin >> a;
    int rubles; cin >> rubles;

    // can we afford x hamburgers with our rubles?
    auto possible = [&](int x) {
        vec<int> needed (3); // amounts needed
        int total_price = 0;
        for (int i = 0; i < 3; i++) {
            needed[i] = recipe[i] * x - have[i];
            needed[i] = max(needed[i], 0LL);
            total_price += needed[i] * price[i];
        }
        
        return rubles >= total_price;
    };

    // find last true
    int l = 0, r = 1e13;
    while (l < r) {
        int mid = (l+r+1)/2;
        if (possible(mid))
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << ln;
}
