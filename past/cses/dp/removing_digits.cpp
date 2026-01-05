#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n;
    cin >> n;

    int count = 0;
    while (n > 0) {
        int temp = n;
        int maxDigit = -1;
        while (temp > 0) {
            maxDigit = max(maxDigit, temp % 10);
            temp /= 10;
        }
        n -= maxDigit;
        count++;
    }
    cout << count << "\n";
}
