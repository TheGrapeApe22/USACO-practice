#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    long long total = 1;
    for (int i = 0; i < n; i++) {
        total *= 2;
        total %= ((long long)1e9 + 7);
    }
    cout << total;
}
