#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n;
    cin >> n;

    long long sum = 0;
    
    for (int i = 0; i < n-1; i++) {
        int k;
        cin >> k;
        sum += k;
    }

    cout << n*(n+1)/2 - sum;
}
