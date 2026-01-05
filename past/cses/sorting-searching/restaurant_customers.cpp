#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    vector<int> arriving (t);
    vector<int> leaving (t);
    for (int i = 0; i < t; i++)
        cin >> arriving[i] >> leaving[i];
    
    sort(arriving.begin(), arriving.end());
    sort(leaving.begin(), leaving.end());

    int i = 0, j = 0, present = 0, maxPresent = 0;
    while (i < t && j < t) {
        if (arriving[i] <= leaving[j]) {
            i++;
            present++;
            maxPresent = max(maxPresent, present);
        } else {
            j++;
            present--;
        }
    }
    while (j < t) {
        j++;
        present--;
    }
    cout << maxPresent << endl;
}
