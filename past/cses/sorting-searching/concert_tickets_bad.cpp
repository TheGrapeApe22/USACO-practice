#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    // tickets, customers
    ll n, m;
    cin >> n >> m;
    vector<ll> tickets (n);
    vector<ll> customers (m);
    for (ll i = 0; i < n; i++)
        cin >> tickets[i];
    sort(tickets.begin(), tickets.end());
    
    vector<bool> bought (n, false);

    for (ll i = 0; i < m; i++) {
        ll k;
        cin >> k;
        // search tickets for tickets[mid] < k < tickets[mid+1]
        ll low = 0, high = tickets.size()-1, mid = -1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (tickets[mid] <= k) {
                // check tickets[mid] <= k < tickets[mid+1]
                if (mid == high || tickets[mid + 1] > k)
                    break;
                low = mid + 1;
                
                // all tickets are too expensive
                if (tickets[low] > k) {
                    mid = -1;
                    break;
                }
            }
            else if (tickets[mid] > k) {
                // check tickets[mid - 1] <= k < tickets[mid]
                if (mid > 0 && tickets[mid - 1] <= k) {
                    mid--;
                    break;
                }
                // k < tickets[mid-1]
                high = mid - 1;
            }
        }

        while (mid >= 0 && bought[mid]) {
            mid--;
        }
        
        if (mid == -1)
            cout << -1 << "\n";
        else {
            cout << tickets[mid] << "\n";
            bought[mid] = true;
        }
    }
}
