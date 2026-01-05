#include <bits/stdc++.h>

using namespace std;

vector<int> getPrimesUntil(int n) {
    vector<bool> isPrime (n, true);
    for (int x = 2; x <= sqrt(n); x++) {
        if (isPrime[x]) {
            for (int i = x*x; i < n; i += x) {
                isPrime[i] = false;
            }
        }
    }
    vector<int> out;
    for (int x = 2; x < n; x++) {
        if (isPrime[x])
            out.push_back(x);
    }
    return out;
}

int main() {
    auto primes = getPrimesUntil(5);

    for (auto x : primes)
        cout << x << " ";
}
