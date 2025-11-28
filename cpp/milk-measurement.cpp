#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <vector>

using namespace std;
int main () {
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

    freopen ("measurement.in", "r", stdin);
    freopen ("measurement.out", "w", stdout);

    int n;
    cin >> n;

    // Bessie, Elsie, Mildred
    unordered_map<char, int> cowIndexes = {
        {'B', 0},
        {'E', 1},
        {'M', 2}
    };

    // store inputs
    vector<array<int, 3>> changes (101);

    for (int i = 0; i < n; i++) {
        int day;
        string name;
        int value;
        cin >> day >> name >> value;

        int cowIndex = cowIndexes[name[0]];

        changes[day][cowIndex] = value;
    }

    // cows <milk_amount, is_best>
    array<pair<int, bool>, 3> cows;
    
    int highest = 0;
    int numChanges = -1;

    for (array change : changes) {
        // factor in input
        for (int i = 0; i < 3; i++) {
            cows[i].first += change[i];
        }

        bool changedToday = false;
        int highest = max(max(cows[0].first, cows[1].first), cows[2].first);
        // for each cow
        for (int i = 0; i < 3; i++) {
            // if you are highest but weren't before
            if (cows[i].first == highest) {
                if (cows[i].second != true) {
                    // update values
                    cows[i].second = true;
                    changedToday = true;
                }
            }
            // if you aren't highest but were before
            else if (cows[i].first < highest) {
                if (cows[i].second != false) {
                    // update values
                    cows[i].second = false;
                    changedToday = true;
                }
            }
        }
        if (changedToday) numChanges++;
    }
    
    cout << numChanges;
}
