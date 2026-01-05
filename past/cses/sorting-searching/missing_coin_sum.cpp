#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> coins (n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    sort(coins.begin(), coins.end());

    long long currentSum = 0;
    for (int i = 0; i < n; i++) {
        if (coins[i] > currentSum + 1)
            break;
        currentSum += coins[i];
    }
    cout << currentSum + 1 << endl;
}
