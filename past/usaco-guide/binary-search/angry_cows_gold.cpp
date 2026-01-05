/*
LETS FUCKING GOOOOO 5th try or something and it took 3 hours
and my solution is beautiful

find rightmost blast pos:
prev = 0
curr = 0
r = 0
loop:
    if (r+1 > maxR)
        return prev + maxR

    if (pos[curr+1] - pos[curr] > maxR)
        return curr + maxR

    r = max(r+1, pos[curr+1] - pos[curr])

    prev = curr
    curr = rightmost <= pos[prev] + r

return 1e9
*/

#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;

auto firstTrue = [](double low, double high, function<bool(double)> f) {
    while (high - low > 0.05) {
        double mid = (low+high) / 2;
        if (f(mid))
            high = mid;
        else
            low = mid + 0.05;
    }
    return low;
};

int main() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n;
    cin >> n;

    vec<int> pos1 (n);
    for (int i = 0; i < n; i++)
        cin >> pos1[i];
    sort(all(pos1));
    
    // reversed and negative, so blastPos function can iterate backwards
    vec<int> pos2 (n);
    for (int i = 0; i < n; i++)
        pos2[i] = -pos1[n - i - 1];

    auto blastPos = [&](double maxR, vec<int>& pos) {
        int r = 0, prev = 0, curr = 0;
        while (curr+1 < n) {
            if (r+1 > maxR)
                return (double)pos[prev] + maxR;
            if (pos[curr+1] - pos[curr] > maxR)
                return (double)pos[curr] + maxR;
            
            r = max(r+1, pos[curr+1] - pos[curr]);
            prev = curr;
            while (curr+1 < n && pos[curr+1] <= pos[prev]+r)
                curr++;
        }
        return (double)1e9;
    };

    auto valid = [&](double x) {
        return blastPos(x, pos1) >= -blastPos(x, pos2);
    };
    
    cout << fixed << setprecision(1) << round(firstTrue(0, 1e9, valid)*10)/10 << ln;
}
