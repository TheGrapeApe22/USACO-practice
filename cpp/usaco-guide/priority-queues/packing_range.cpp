/*
FULL ATTEMPT 3
ranges <start, end>
sort ranges (by start)

pq (by end)

int t = 0
while ranges left:
    if (pq empty && (next range).start > t)
        t = (next range).start
    pq.push(all ranges with start <= t)

    if (pq.top.end < t)
        // a range couldn't be accomodated
        return false

    // remove the one that ends earliest
    t++
    pq.pop()
return true
*/

#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using pii = pair<int, int>;

bool solve(int n) {
    vec<pii> ranges (n);
    for (pii& x : ranges)
        cin >> x.first >> x.second;
    sort(all(ranges));
    
    priority_queue<pii, vec<pii>, greater<pii>> pq;
    int j = 0;
    int t = 0;
    while (!pq.empty() || j < n) {
        if (j < n && ranges[j].first > t)
            t = ranges[j].first;
        
        // pq.push(all ranges with start <= t)
        while (j < n && ranges[j].first <= t) {
            pq.push({ranges[j].second, ranges[j].first});
            j++;
        }
        
        if (pq.top().first < t)
            return false;
        
        t++;
        pq.pop();
    }
    return true;
}

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n; cin >> n;
        cout << (solve(n) ? "yes" : "no") << ln;
    }
}
