#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int rows, cols;
        cin >> rows >> cols;
        vector<vector<int>> matrix (rows, vector<int> (cols));
        int maxVal = -1;
        for (int a = 0; a < rows; a++) {
            for (int b = 0; b < cols; b++) {
                int k;
                cin >> k;
                matrix[a][b] = k;
                maxVal = max(maxVal, k);
            }
        }

        bool broken = false;
        int r = -1, c = -1;
        int a1 = -1, b1 = -1, a2 = -1, b2 = -1;
        for (int a = 0; a < rows; a++) {
            for (int b = 0; b < cols; b++) {
                if (matrix[a][b] != maxVal) continue;
                if (a == r || b == c) continue;
                if (r != -1 && c != -1) {
                    // both exist
                    cout << maxVal << "\n";
                    broken = true;
                    break;
                }
                if (r != -1 && c == -1) {
                    // only r exists
                    c = b;
                    continue;
                }
                else if (r == -1 && c != -1) {
                    // only c exists
                    r = a;
                    continue;
                }
                
                if (a1 == -1) {
                    a1 = a;
                    b1 = b;
                }
                else if (a2 == -1) {
                    if (a == a1)
                        r = a;
                    else if (b == b1)
                        c = b;
                    else {
                        a2 = a;
                        b2 = b;
                    }
                }
                else {
                    // a1 and a2 are defined
                    if (a == a1) {
                        r = a1;
                        c = b2;
                    }
                    else if (a == a2) {
                        r = a2;
                        c = b1;
                    }
                    else if (b == b1) {
                        c = b1;
                        r = a2;
                    }
                    else if (b == b2) {
                        c = b2;
                        r = a1;
                    }
                    else {
                        cout << maxVal << "\n";
                        broken = true;
                        break;
                    }
                }
            }
            if (broken) break;
        }
        if (!broken)
            cout << maxVal-1 << "\n";
    }
}
