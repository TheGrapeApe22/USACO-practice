#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> indexes;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        indexes[k] = i;
    }
    int counter = 1;
    int prev = 1;
    for (int i = 2; i <= n; i++) {
        if (indexes[i] < indexes[prev])
            counter++;
        prev = i;
    }
    cout << counter << endl;
}
