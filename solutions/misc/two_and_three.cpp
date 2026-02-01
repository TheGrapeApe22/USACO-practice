// https://codeforces.com/group/pkQzrtUYed/contest/576945/problem/C
/*
4, 5: p1 can force either
3: p2 can force p1 end
2: p2 can force p1 end
1: p2 can force p2 end (ignore)

4s + 5s is odd: nino wins
2s + 3s is odd: nino wins
miku wins
*/

#include <bits/stdc++.h>
using namespace std;

int reduce (int x) {
    while (x >= 6) x /= 6;
    return x;
}

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n; cin >> n;
        int fourfives = 0;
        int twothrees = 0;
        for (int j = 0; j < n; j++) {
            int k; cin >> k;
            k = reduce(k);
            if (k == 2 || k == 3)
                twothrees++;
            if (k == 4 || k == 5)
                fourfives++;
        }
        if (fourfives % 2 || twothrees % 2)
            cout << "Nino\n";
        else
            cout << "Miku\n";
    }
}
