// https://codeforces.com/problemset/problem/550/A
// silly mistake implementation
#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define _ << " " <<
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    string s;
    cin >> s;

    int firstBA = -1, lastBA = -1, firstAB = -1, lastAB = -1;

    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == 'A' && s[i+1] == 'B') {
            if (firstAB == -1) firstAB = i;
            lastAB = i;
        }
        if (s[i] == 'B' && s[i+1] == 'A') {
            if (firstBA == -1) firstBA = i;
            lastBA = i;
        }
    }

    if (firstBA == -1 || firstAB == -1)
        cout << "NO\n";
    else if (firstAB < lastBA-1 || firstBA < lastAB-1)
        cout << "YES\n";
    else
        cout << "NO\n";
}
