#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    if (n == 1) {
        cout << "1\n";
    }
    else if (n <= 3) {
        cout << "NO SOLUTION\n";
    }
    else {
        for (int x = n; x > 4; x -= 2)
            cout << x << " ";
        cout << "3 1 4 2 ";
        for (int x = n-1; x > 4; x -= 2)
            cout << x << " ";
        cout << endl;
    }
}
