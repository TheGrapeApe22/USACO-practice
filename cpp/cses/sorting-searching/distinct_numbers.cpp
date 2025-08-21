#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        s.insert(k);
    }
    cout << s.size() << endl;
}
