#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, pos;
        cin >> n >> pos;
        
        int minPos, maxPos;
        cin >> minPos;
        for (int j = 1; j < n; j++)
            cin >> maxPos;
        if (n == 1) maxPos = minPos;

        cout << maxPos - minPos + min(abs(pos - minPos), abs(pos - maxPos)) << "\n";
    }
}
