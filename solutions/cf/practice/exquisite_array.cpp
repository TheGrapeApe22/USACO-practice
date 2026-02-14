// https://codeforces.com/problemset/problem/2184/E 2/14/26
// HOLY SHIT THIS WORKED the editorial didn't make sense to me so i used gemini to explain and came up with some wacky monotonic stack solution AND IT WORKED
#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define _ << " " <<
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using pii = pair<int, int>;

#define int long long

template<typename T> ostream& operator<<(ostream& out, const vector<T>& v) {
    cout << "[";
    for (int i = 0; i < (int)v.size()-1; i++) cout << v[i] << ", ";
    cout << v[(int)v.size()-1] << "]";
    return out;
}

/*
for each k:
 - how many subarrays contain all x>k?
 - how many subarrays contain a single x<=k?

the first number to the right less than you will cover all your subarrays containing it. you just have to cover all subarrays ending before that (>= you).

the first number on the left less than you will cover all your subarrays containing it. you just have to cover all subarrays

count from nearest left number <= you, to nearest right number < you


stack.push(-1)
iterate array:
    while arr[i] <= arr[stack.top()] or (check for -1):
        smallerEqualLeft[stack.top()] = i
        stack.pop()
    stack.push(arr[i])
while stack.size():
    nearestRight[stack.top()] = n
    stack.pop()

*/

void solve(vec<int>& arr, int n) {
    // construct smallerRight
    stack<int> st;
    st.push(-1);
    vec<int> smallerRight (n, -1);
    for (int i = 0; i < n; i++) {
        while (st.top() != -1 && arr[i] < arr[st.top()]) {
            smallerRight[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while (st.top() != -1) {
        smallerRight[st.top()] = n;
        st.pop();
    }

    // construct smallerEqualLeft
    // st is reset to {-1}
    vec<int> smallerEqualLeft (n, -1);
    for (int i = 0; i < n; i++) {
        while (st.top() != -1 && arr[i] < arr[st.top()]) {
            st.pop();
        }
        smallerEqualLeft[i] = st.top();
        st.push(i);
    }

    vec<int> countK (n);
    // actually solve the problem
    for (int i = 0; i < n; i++) {
        if (arr[i] >= n) continue;
        countK[arr[i]] += (i - smallerEqualLeft[i]) * (smallerRight[i] - i);
    }
    
    // cout << arr << ln << smallerEqualLeft << ln << smallerRight << ln << countK << ln;

    for (int i = 1; i < n; i++)
        countK[i] += countK[i-1];
    
    
    for (int i = 0; i < n; i++)
        cout << n*(n+1)/2 - countK[i] << " ";
    
    cout << ln;
}

signed main() {
    int t; cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int n; cin >> n;
        int prev; cin >> prev;
        vec<int> diff (n-1);
        for (int i = 0; i < n-1; i++) {
            int k; cin >> k;
            diff[i] = abs(k - prev);
            prev = k;
        }
        solve(diff, n-1);
    }
}
