#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    long long counter = 0;
    
    long long prev;
    cin >> prev;

    for (int i = 1; i < n; i++) {
        // cout << prev << ", ";
        long long k;
        cin >> k;

        if (prev > k)
            counter += prev - k;
        else
            prev = k;
    }

    cout << counter << endl;
}
