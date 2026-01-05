#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> indexes (n);
    vector<int> values (n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        values[i] = k-1;
        indexes[k-1] = i;
    }
    
    int cycles = 1;
    for (int x = 1; x < n; x++) {
        if (indexes[x] < indexes[x-1])
            cycles++;
    }
    // cout << cycles << endl;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        
        // subtract cycles
        set<int> changes {values[a], values[a]+1, values[b], values[b]+1};
        set<int> checkValues;
        for (int x : changes) {
            if (x != 0 && x != n)
                checkValues.insert(x);
        }

        for (int x : checkValues) {
            if (indexes[x] < indexes[x-1])
                cycles--;
        }
        // swap
        swap(values[a], values[b]);
        swap(indexes[values[a]], indexes[values[b]]);

        // add cycles
        for (int x : checkValues) {
            if (indexes[x] < indexes[x-1])
                cycles++;
        }

        cout << cycles << "\n";
    }
}
