#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    set<int> s;
    for (int i = 1; i <= n; i++) {
        s.insert(i);
    }
    auto it = ++s.begin();
    while (true) {
        if (it == s.end()) it = s.begin();
        
        cout << *it << " ";
        it = s.erase(it);
        if (s.empty()) break;
        
        if (it == s.end()) it = s.begin();
        it++;
    }
    cout << endl;
}
