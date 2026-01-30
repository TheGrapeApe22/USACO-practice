// https://leetcode.com/problems/longest-repeating-character-replacement/
#include <bits/stdc++.h>
using namespace std;
/*
do a separate search for each letter. for ex, A.
l=0, r=0
while r is not at the end:
    move r to the right as far as possible
    count [l, r]
    l++
    if k=0, set l and r to next a
    if r<l, r++ 
*/
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(), ans = 0;
        for (char A = 'A'; A <= 'Z'; A++) {
            int l = 0, r = 0, changesLeft = k;
            if (s[l] != A) changesLeft--;
            while (r < n) {
                // check for case k=0, s[l] != A
                if (k == 0) {
                    while (r < n && s[r] != A) {
                        r++;
                        l = r;
                    }
                }

                while (r < n-1 && changesLeft > 0 || s[r+1] == A) {
                    r++;
                    if (s[r] != A)
                        changesLeft--;
                }

                // cout << string{A} << " " << l << " " << r << "\n";
                ans = max(ans, r-l+1);
                
                if (s[l] != A) changesLeft++;
                l++;
                if (r == n-1) break;

                if (r < l) {
                    r = l;
                    changesLeft = k;
                    if (s[l] != A) changesLeft--;
                }
            }
        }
        return ans;
    }
};