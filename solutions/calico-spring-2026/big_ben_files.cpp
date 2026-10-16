#include <bits/stdc++.h>

using namespace std;

void solve(string& s1, string& s2) {
    int j = 0;
    for (int i = 0; i < (int)s2.size(); i++) {
        while (s1[j] != s2[i]) {
            cout << "#";
            j++;
        }
        cout << s1[j++];
    }
    while (j < (int)s1.size()) {
        cout << "#";
        j++;
    }
    cout << "\n";
}

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int t; cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        string s1, s2;
        cin >> s1 >> s2;
        solve(s1, s2);
    }
}
