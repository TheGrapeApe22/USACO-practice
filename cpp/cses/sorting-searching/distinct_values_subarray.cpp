#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// num of subarrays given a length
ll calculate(ll n) {
    return n*(n+1)/2;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> values (n);
    for (ll i = 0; i < n; i++) {
        cin >> values[i];
    }

    ll numSubarrays = 0;
    ll left = 0;
    ll prevRight = -1;
    map<ll, ll> indexes;
    for (ll right = 0; right < n; right++) {
        ll curr = values[right];
        if (indexes[curr] > left) {
            // cout << left << " " << right << "\n";
            if (prevRight > left)
                numSubarrays -= calculate(prevRight - left);
            numSubarrays += calculate(right - left);
            prevRight = right;

            left = indexes[curr];
            // cout << numSubarrays << "\n";
        }
        indexes[curr] = right + 1;
    }
    if (prevRight > left)
        numSubarrays -= calculate(prevRight - left);
    numSubarrays += calculate(n - left);
    cout << numSubarrays << endl;
}
