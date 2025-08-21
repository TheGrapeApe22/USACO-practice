#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> songs (n);
    for (int i = 0; i < n; i++)
        cin >> songs[i];

    map<int, int> indexes;
    int start = 0;
    int maxSize = 0;
    for (int end = 0; end < n; end++) {
        int current = songs[end];

        // cout << indexes[current] << ", ";
        // if (indexes[current] != 0)
        start = max(start, indexes[current]);
        
        indexes[current] = end + 1;

        // cout << start << " " << end << endl;
        maxSize = max(maxSize, end - start + 1);
    }
    cout << maxSize << endl;
}
