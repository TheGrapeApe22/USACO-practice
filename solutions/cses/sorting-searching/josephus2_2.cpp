#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    indexed_set s;
    for (int i = 1; i <= n; i++) {
        s.insert(i);
    }
    
    int i = k;

    while (!s.empty()) {
        i %= s.size();

        auto it = s.find_by_order(i);
        cout << *it << " ";
        s.erase(it);

        i += k;
    }
    cout << endl;
}
