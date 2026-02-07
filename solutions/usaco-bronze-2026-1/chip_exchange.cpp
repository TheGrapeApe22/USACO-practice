#include <bits/stdc++.h>
#define ln "\n"
#define _ << " " <<
using namespace std;
using ll = long long;

/*
A, B:	initial chips
ca, cb:	exchange rates
fa:	target number of A

maxAs(B, ca, cb) = floor(B*ca/cb)
in order to get A a's, you need A*cb/ca b's.
you need fA-A a's.
*/

ll divUp (ll a, ll b) {
    return (a+b-1LL)/b;
}

ll solve(ll a, ll b, ll ca, ll cb, ll fa) {
    ll ans;
    if (ca > cb) {
        // pour waste to b, then everything else to a
        ll waste = cb - b%cb - 1LL;
        // cout << "waste" _ waste << ln;
        ans = fa - a - b/cb*ca;
        if (ans > 0) ans += waste;
    }
    else {
        // pour waste to a, then everything else to b
        ll waste = (fa-a-1)%ca;
        // cout << "waste" _ waste << ln;
        ans = divUp((fa-a), ca)*cb - b + waste;
    }
    return max(0LL, ans);
}

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    ll t;
    cin >> t;

    for (ll i = 0; i < t; i++) {
        ll a, b, ca, cb, fa;
        cin >> a >> b >> ca >> cb >> fa;
        cout << solve(a, b, ca, cb, fa) << ln;
    }
}
