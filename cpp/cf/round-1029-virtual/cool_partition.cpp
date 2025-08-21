#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int k;
        cin >> k;
        set<int> prev;
        prev.insert(k);
        set<int> curr;
        int count = 1;
        for (int j = 1; j < n; j++) {
            int k;
            cin >> k;
            curr.insert(k);
            auto it = prev.find(k);
            if (it != prev.end()) {
                prev.erase(it);
                if (prev.empty()) {
                    count++;
                    swap(prev, curr);
                }
            }
        }
        cout << count << "\n";
    }
}
