#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, x;
        cin >> n >> x;

        int leftDoor = 11;
        int rightDoor = -1;
        for (int j = 0; j < n; j++) {
            int door;
            cin >> door;
            if (door == 1) {
                leftDoor = min(leftDoor, j);
                rightDoor = max(rightDoor, j);
            }
        }

        if (rightDoor == -1 || (rightDoor-leftDoor+1 <= x))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
