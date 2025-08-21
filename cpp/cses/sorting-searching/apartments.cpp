#include <bits/stdc++.h>

using namespace std;

int main() {
    // num people, num apartments, max diff
    long long p, a, d;
    cin >> p >> a >> d;
    vector<long long> people (p);
    vector<long long> apartments (a);
    for (long long i = 0; i < p; i++)
        cin >> people[i];
    for (long long i = 0; i < a; i++)
        cin >> apartments[i];
    
    sort(people.begin(), people.end());
    sort(apartments.begin(), apartments.end());

    long long numMatches = 0;
    long long i = 0, j = 0;
    while (i < p && j < a) {
        if (abs(people[i] - apartments[j]) <= d) {
            numMatches++;
            i++;
            j++;
        } else if (people[i] > apartments[j]) {
            j++;
        } else {
            i++;
        }
    }
    cout << numMatches << endl;
}
