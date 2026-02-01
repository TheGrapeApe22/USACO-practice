#include <bits/stdc++.h>

using namespace std;
// cout << iterable container
ostream& operator<<(ostream& out, const vector<int>& v) {
    out << "[";
    if (v.size() > 0) {
        auto last = --v.end();
        for (auto it = v.begin(); it != last; it++)
            out << *it << ", ";
        out << *last;
    }
    out << "]";
    return out;
}
int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> a (n);
        vector<int> b (n);
        int numOps = 0;
        string output = "";
        for (int j = 0; j < n; j++)
            cin >> a[j];
        for (int j = 0; j < n; j++) {
            cin >> b[j];
            if (a[j] > b[j]) {
                output += "3 " + to_string(j+1) + "\n";
                numOps++;
                swap(a[j], b[j]);
            }
        }
        auto sort = [&](vector<int>& v, int code) {
            for (int i = 0; i < n-1; i++) {
                for (int j = n-1; j > i; j--) {
                    if (v[j-1] > v[j]) {
                        // cout << a << endl;
                        // cout << b << endl;
                        output += to_string(code) + " " + to_string(j-1 + 1) + "\n";
                        numOps++;
                        swap(v[j-1], v[j]);
                    }
                }
            }
        };
        sort(a, 1);
        sort(b, 2);
        cout << numOps << "\n";
        cout << output;
    }
}
