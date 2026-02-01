// https://codeforces.com/problemset/problem/466/C
// mistakes: third pointer has to be at the end. and using int instead of long long like 3 times.
#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define _ << " " <<
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n; cin >> n;
    
    vec<ll> prefix (n+1);
    for (int i = 1; i <= n; i++) {
        cin >> prefix[i];
        prefix[i] += prefix[i-1];
    }

    if (prefix[n] % 3 != 0) {
        cout << 0 << ln;
        return 0;
    }

    ll div_sum = prefix[n] / 3;

    ll sequences1 = 0;
    ll sequences2 = 0;
    for (int i = 1; i < n; i++) {
        if (prefix[i] == 2*div_sum)
            sequences2 += sequences1;
        if (prefix[i] == div_sum)
            sequences1++;
    }

    cout << sequences2 << ln;
}
