#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long a, b;
        cin >> a >> b;

        long long a1 = max(a, b);
        long long b1 = min(a, b);
        long long equalized = (2*b1 - a1);

        if (equalized >= 3 && equalized % 3 == 0 || a1 == b1*2)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
