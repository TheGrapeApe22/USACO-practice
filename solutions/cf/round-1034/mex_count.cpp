#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int t;
    cin >> t;

    for (int t1 = 0; t1 < t; t1++) {
        int n;
        cin >> n;

        vector<int> counts (n+1, 0);
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            counts[k]++;
        }

        int first0 = n+1;
        for (int i = 0; i <= n; i++) {
            if (counts[i] == 0) {
                first0 = i;
                break;
            }
        }

        vector<int> counts2 (n+1, 0);
        for (int i = 0; i <= first0; i++) {
            counts2[counts[i]]++;
        }

        // for (int x : counts2)
        //     cout << x << " ";
        // cout << "\n";

        vector<int> prefix (n+1, 0);
        prefix[0] = counts2[0];
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i-1] + counts2[i];
        }
        for (int i = 1; n - first0 + i <= n; i++) {
            prefix[n - first0 + i] -= i;
        }

        for (int x : prefix)
            cout << x << " ";
        cout << "\n";
    }
}
