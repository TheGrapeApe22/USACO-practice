#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool possible(vector<int>& counts, int len) {
    int maxCount = *max_element(counts.begin(), counts.end());
    return 2*maxCount <= len+1;
}

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    string input;
    cin >> input;
    int n = input.size();

    vector<int> counts(26, 0);
    for (int i = 0; i < n; i++) {
        char letter = input[i];
        counts[letter - 'A']++;
    }

    if (!possible(counts, n)) {
        cout << "-1\n";
        return 0;
    }

    string out = "";
    // for each char in input
    for (int i = 0; i < n; i++) { // O(n)
        for (int letter = 0; letter < 26; letter++) { // O(1)
            if (counts[letter] == 0) continue;
            // if letter = previous letter
            if (!out.empty() && letter+'A' == out[out.size()-1])
                continue;
            // find earliest letter
            counts[letter]--;
            if (possible(counts, n - out.size() - 1)) { // O(1)
                out += (char)('A'+letter);
                break;
            }
            counts[letter]++;
        }
    }
    cout << out << "\n";
}
