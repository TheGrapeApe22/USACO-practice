#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    string input;
    cin >> input;
    
    vector<int> letterCounts (26, 0);
    
    for (int i = 0; i < input.size(); i++) {
        letterCounts[input[i] - 'A']++;
    }
    
    int odds = 0;
    for (int count : letterCounts) {
        odds += count % 2;
    }
    if (odds > 1) {
        cout << "NO SOLUTION\n";
        return 0;
    }

    char oddChar = '?';

    for (int i = 0; i < 26; i++) {
        int count = letterCounts[i];
        if (count % 2 == 0) {
            for (int j = 0; j < count / 2; j++) {
                cout << (char)('A' + i);
            }
        } else {
            oddChar = (char)('A' + i);
        }
    }
    if (oddChar != '?') {
        for (int i = 0; i < letterCounts[oddChar - 'A']; i++)
            cout << oddChar;
    }
    for (int i = 25; i >= 0; i--) {
        int count = letterCounts[i];
        if (count % 2 == 0) {
            for (int j = 0; j < count / 2; j++) {
                cout << (char)('A' + i);
            }
        } else {
            oddChar = (char)('A' + i);
        }
    }
}
