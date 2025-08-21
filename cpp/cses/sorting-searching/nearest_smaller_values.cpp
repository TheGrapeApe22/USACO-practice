#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n;
    cin >> n;

    stack<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        
        while (!st.empty() && k <= st.top().first)
            st.pop();
        
        if (st.empty())
            cout << "0 ";
        else
            cout << st.top().second << " ";

        st.push({k, i+1});
    }
    cout << "\n";
}
