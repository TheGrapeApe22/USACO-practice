#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;
    
    long long target = n*(n+1)/2;

    if (target % 2 == 1) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    target /= 2;
    long long sum = 0;
    long long i = n;
    while (sum + i < target) {
        sum += i;
        i--;
    }
    long long remainder = target - sum;

    cout << (n - i + 1) << "\n";
    for (long long j = i+1; j <= n; j++)
        cout << j << " ";
    cout << remainder << "\n";

    cout << i-1 << "\n";
    for (long long j = 1; j <= i; j++) {
        if (j != remainder)
            cout << j << " ";
    }
    cout << endl;
}
