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
        vector<int> nums (n);
        vector<int> minForward (n);
        vector<int> maxBackward (n);

        for (int i = 0; i < n; i++)
            cin >> nums[i];
        
        minForward[0] = nums[0];
        for (int i = 1; i < n; i++)
            minForward[i] = min(minForward[i-1], nums[i]);
        
        maxBackward[n-1] = nums[n-1];
        for (int i = n-2; i >= 0; i--)
            maxBackward[i] = max(maxBackward[i+1], nums[i]);
        
        for (int i = 0; i < n; i++) {
            if (i == 0 || minForward[i-1] > nums[i])
                cout << 1;
            else if (i == n-1 || maxBackward[i+1] < nums[i])
                cout << 1;
            else
                cout << 0;
        }
        cout << "\n";
    }
}
