#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// print container
template<typename T>
void print (const T& v, bool newline=true) {
    cout << "[";
    if (v.size() > 0) {
        auto last = --v.end();
        for (auto it = v.begin(); it != last; it++)
            cout << *it << ", ";
        cout << *last;
    }
    cout << "]";
    if (newline)
        cout << "\n";
}

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    // num books, total money
    int n, x;
    cin >> n >> x;
    
    // price, pages
    vector<pair<int, int>> books;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        books.push_back({k, 0});
    }
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        books[i].second = k;
    }

    // f(n) = max(f(n-cost1) + pages1) for all books
    vector<int> maxPages (x+1);
    for (auto [price, pages] : books) {
        for (int i = x; i > 0; i--) {
            if (i - price >= 0) {
                maxPages[i] = max(maxPages[i], maxPages[i - price] + pages);
            }
        }
    }
    // print(maxPages);
    
    cout << maxPages[x] << "\n";
}
