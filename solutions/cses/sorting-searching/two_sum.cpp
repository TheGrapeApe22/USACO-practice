#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    map<long long, int> inputs;
    for (int i = 1; i <= n; i++) {
        long long k;
        cin >> k;
        auto it = inputs.find(x - k);
        if (it != inputs.end()) {
            cout << (*it).second << " " << i << endl;
            return 0;
        }
        inputs.insert({k, i});
    }
    cout << "IMPOSSIBLE\n";
}
