#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define _ << " " <<
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using pii = pair<int, int>;

/*
construct matrix moo_freq (n, n-1, n-2)

for each of the 2^n combinations of letters:
    iterate moo_freq to calculate score
*/

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n, k;
    cin >> n >> k;

    vec<vec<vec<int>>> moo_freq (n, vec<vec<int>> (n, vec<int> (n)));
    vec<int> score_freq (k+1);

    for (int i = 0; i < k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--; c--;
        if (b > c) swap(b, c);
        moo_freq[a][b][c]++;
    }

    // for (int a = 0; a < n; a++) {
    //     for (int b = 0; b < n; b++) {
    //         for (int c = 0; c < n; c++) {
    //             cout << a _ b _ c _ moo_freq[a][b][c] << ln;
    //         }
    //     }
    // }
    

    for (int letters = 0; letters < (1<<n); letters++) {
        int score = 0;
        for (int a = 0; a < n; a++) {
            if ((letters>>a)&1) {
                for (int b = 0; b < n; b++) {
                    if ((~letters>>b)&1) {
                        for (int c = b+1; c < n; c++) {
                            if ((letters>>a)&1 && (~letters>>b)&1 && ((~letters>>c)&1))
                                score += moo_freq[a][b][c];
                        }
                    }
                }
            }
        }
        score_freq[score]++;
    }

    for (int i = k; i >= 0; i--) {
        // cout << i _ score_freq[i] << ln;
        if (score_freq[i] > 0) {
            cout << i _ score_freq[i] << ln;
            return 0;
        }
    }
}
