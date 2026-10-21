/*
    failed priority queue solution :/
    O(m log n) = O(n^2 log n)
*/

#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;

    vec<int> nums (n);
    for (int& x : nums)
        cin >> x;
    sort(all(nums), greater<int>());
    
    priority_queue<vec<int>> pq;
    unordered_set<int> pushed;

    auto push = [&](int a, int b) {
        if (a >= n || b >= n) return;
        
        int compress = a*1e5 + b;
        if (pushed.find(compress) != pushed.end()) return;
        pushed.insert(compress);
        
        pq.push({nums[a] + nums[b], a, b});
    };
    
    int sum = 0;
    push(0, 0);
    for (int i = 0; i < m; i++) {
        sum += pq.top()[0];
        int a = pq.top()[1];
        int b = pq.top()[2];

        // cout << pq.top()[0] << " " << a << " " << b << ln;
        pq.pop();

        push(a+1, b);
        push(a, b+1);
    }
    cout << sum << ln;
}
