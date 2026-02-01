#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> inputs (n);
        for (int j = 0; j < n; j++)
            cin >> inputs[j];
        
        int diff = inputs[1] - inputs[0];
        bool broken = false;
        for (int j = 2; j < n; j++) {
            if (inputs[j] - inputs[j-1] != diff) {
                cout << "NO\n";
                broken = true;
                break;
            }
        }
        if (broken) continue;
        int minValue = inputs[0];
        if (diff < 0) minValue = inputs[inputs.size()-1];

        if (abs(diff) > minValue || (minValue - abs(diff))%(n+1) != 0) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
    }
}
