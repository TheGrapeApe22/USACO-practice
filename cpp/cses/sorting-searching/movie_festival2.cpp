#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<long long, long long>> movies (n);
    for (int i = 0; i < n; i++) {
        cin >> movies[i].second;
        cin >> movies[i].first;
    }
    sort(movies.begin(), movies.end());

    int counter = 0;
    int end = 0;
    for (int i = 0; i < n; i++) {
        if (movies[i].second >= end) {
            end = movies[i].first;
            counter++;
        }
    }
    
    cout << counter << endl;
}
