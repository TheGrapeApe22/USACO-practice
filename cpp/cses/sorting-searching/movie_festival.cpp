#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<long long, long long>> movies (n);
    for (int i = 0; i < n; i++) {
        cin >> movies[i].first;
        cin >> movies[i].second;
    }
    sort(movies.begin(), movies.end());

    int counter = 0;
    int i = 1;
    int minIndex = 0; // index of movie with earliest end
    while (minIndex < n) {
        // iterate through all overlapping movies
        while (i < n && movies[i].first < movies[minIndex].second) {
            // set minIndex if movie[i] ends earlier
            if (movies[i].second <= movies[minIndex].second)
                minIndex = i;
            
            i++;
        }
        // reset minIndex for next search
        minIndex = i;
        counter++;
    }
    cout << counter << endl;
}
