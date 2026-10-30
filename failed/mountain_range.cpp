/*
https://cses.fi/problemset/task/3314/

BRUHHH I HAD ALL THE MONOTONIC STACK STUFF
but it fails on 
4
2 2 1 3
because i assumed there would be no duplicates.
apparently ts requires a segment tree >:((
frick cses
*/

#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define _ << " " <<
#define all(x) (x).begin(), (x).end()
#define int long long
using namespace std; using ll = long long; using pii = pair<int, int>; using vi = vector<int>;
template<typename T> ostream& operator<<(ostream& out, const vector<T>& v) {
    cout << "["; for (size_t i = 0; i+1 < v.size(); i++) cout << v[i] << ", "; cout << *v.rbegin() << "]"; return out;
}

vi heights;
vi dp;
vi right_move;
vi left_move;

int solve(int i) {
    if (dp[i] != -1)
        return dp[i];

    dp[i] = 1;
    if (right_move[i] != -1)
        dp[i] = max(dp[i], 1 + solve(right_move[i]));
    if (left_move[i] != -1)
        dp[i] = max(dp[i], 1 + solve(left_move[i]));
    
    return dp[i];
}

signed main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    heights = vi(n);
    dp = vi(n, -1);
    right_move = vi(n, -1);
    left_move = vi(n, -1);

    for (int& x : heights)
        cin >> x;

    stack<int> st;
    for (int i = 0; i < n; i++) {
        while(!st.empty() && heights[st.top()] <= heights[i])
            st.pop();
        
        if (!st.empty() && (right_move[i] == -1 || heights[st.top()] > heights[right_move[i]]))
            right_move[st.top()] = i;
        st.push(i);
    }
    st = stack<int>();
    for (int i = n-1; i >= 0; i--) {
        while(!st.empty() && heights[st.top()] <= heights[i])
            st.pop();
        
        if (!st.empty() && (left_move[i] == -1 || heights[st.top()] > heights[left_move[i]]))
            left_move[st.top()] = i;
        st.push(i);
    }

    
    int best = -1;
    for (int i = 0; i < n; i++)
        best = max(best, solve(i));
    cout << best << ln;
    
    cout << left_move << ln << right_move << ln;
    cout << heights << ln;
    cout << dp << ln;
}
