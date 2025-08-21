#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<long long> prefix_sums (n);

    cin >> prefix_sums[0];
    for (int i = 1; i < n; i++) {
        int k;
        cin >> k;

        prefix_sums[i] = prefix_sums[i-1] + k;
    }

    long long largest_val = prefix_sums[0];
    long long smallest_val = 0;
    long long largest_diff = largest_val;

    for (int i = 1; i < n; i++) {
        if (prefix_sums[i - 1] < smallest_val) {
            smallest_val = prefix_sums[i - 1];
            // largest_val must be to the right of smallest_val
            largest_val = prefix_sums[i];
        }
        largest_val = max(largest_val, prefix_sums[i]);
        
        largest_diff = max(largest_diff, largest_val - smallest_val);
    }

    cout << largest_diff << endl;
}
