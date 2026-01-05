#include <bits/stdc++.h>

using namespace std;

void moveBlock(int start, int end) {
    cout << start << " " << end << "\n";
}
void moveTower(int n, int start, int end) {
    if (n == 1)
        moveBlock(start, end);
    else {
        int third = 1+2+3 - start - end;
        moveTower(n-1, start, third);
        moveBlock(start, end);
        moveTower(n-1, third, end);
    }
}

int main() {
    int n;
    cin >> n;
    cout << pow(2, n) - 1 << "\n";
    moveTower(n, 1, 3);
}
