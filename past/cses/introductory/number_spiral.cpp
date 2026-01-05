#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long row, col;
        cin >> row >> col;

        if (row >= col) {
            if (row % 2 == 0)
                cout << (row * row - col + 1);
            else
                cout << ((row-1)*(row-1) + col);
        }
        else {
            if (col % 2 == 0)
                cout << ((col-1)*(col-1) + row);
            else
                cout << (col * col - row + 1);
        }
        cout << endl;
    }
}
