#include <bits/stdc++.h>

using namespace std;

// print iterable
template <typename it>
ostream& operator<<(ostream& out, const multiset<it>& v) {
    out << "[";
    if (v.size() > 0) {
        auto last = --v.end();
        for (auto it = v.begin(); it != last; it++)
            out << *it << ", ";
        out << *last;
    }
    out << "]\n";
    return out;
}

int main() {
    // road goes from [0, x]
    int x, n;
    cin >> x >> n;

    set<int> lights {0, x};
    multiset<int> lengths {x};

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        auto left = lights.insert(k).first;
        // auto left = lights.find(k);
        auto right = left;
        left--; right++;
        int diff = *right - *left;
        
        lengths.erase(lengths.find(diff));
        lengths.insert(*right - k);
        lengths.insert(k - *left);

        // cout << lengths;
        // largest element
        cout << *lengths.rbegin() << "\n";
    }
}
