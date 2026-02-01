#include <bits/stdc++.h>

using namespace std;

int f(int a, int b) {
    string a1 = to_string(a);
    string b1 = to_string(b);
    int out = 0;
    for (int i = 0; i < (int)a1.size(); i++) {
        if (a1[i] == b1[i])
            out++;
    }
    return out;
}
int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        int minVal = 100;
        for (int x = a; x <= b; x++) {
            minVal = min(minVal, f(a, x) + f(x, b));
        }
        cout << minVal << "\n";
    }
}
