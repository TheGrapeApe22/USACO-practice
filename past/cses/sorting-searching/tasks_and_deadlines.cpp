#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    ll n;
    cin >> n;

    multimap<ll, ll> tasks;
    for (ll i = 0; i < n; i++) {
        ll duration, deadline;
        cin >> duration >> deadline;
        tasks.emplace(duration, deadline);
    }

    ll t = 0;
    ll reward = 0;
    for (auto [duration, deadline] : tasks) {
        t += duration;
        reward += deadline - t;
        // cout << reward << " ";
    }
    cout << reward << "\n";
}
