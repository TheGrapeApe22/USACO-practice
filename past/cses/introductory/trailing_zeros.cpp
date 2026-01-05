#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;
    
    int counter = 0;
    for (long long product = 5; product <= n; product *= 5) {
        counter += n / product;
    }

    cout << counter << endl;
}
