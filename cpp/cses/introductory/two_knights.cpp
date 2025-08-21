#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    cin >> n;
    
    for (long long k = 1; k <= n; k++) {
        long long numSquares = k*k;
        long long total = numSquares*(numSquares - 1) / 2;

        total -= (k-2) * (k-1) * 4;
        cout << total << "\n";
    }
}
