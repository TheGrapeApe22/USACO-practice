#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        ll k;
        cin >> k;
        ll start = 1;
        ll numNumbers = 9;
        ll numDigits = 1;
        
        while (start <= k) {
            start += numNumbers * numDigits;
            numNumbers *= 10;
            numDigits++;
        }
        numDigits--; numNumbers /= 10; start -= numNumbers * numDigits;
        
        ll diff = k - start;
        ll index = diff % numDigits;
        // cout << start << " " << start + diff/numDigits << " " << index << " ";
        cout << to_string((ll)pow(10, numDigits - 1) + diff/numDigits).at(index) << endl;
    }
}
