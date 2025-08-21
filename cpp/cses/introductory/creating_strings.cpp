#include <bits/stdc++.h>

using namespace std;

vector<string> generate(string current, string remaining) {
    vector<string> out;
    if (remaining == "") {
        out.push_back(current);
        return out;
    }
    for (int i = 0; i < remaining.size(); i++) {
        if (i != 0 && remaining[i] == remaining[i-1])
            continue;
        vector<string> smaller = generate(current + remaining[i], remaining.substr(0, i) + remaining.substr(i+1));
        for (string s : smaller) {
            out.push_back(s);
        }
    }
    return out;
}

int main() {
    string input;
    cin >> input;
    sort(input.begin(), input.end());
    vector<string> combinations = generate("", input);
    cout << combinations.size() << "\n";
    for (string s : combinations) {
        cout << s << "\n";
    }
}

