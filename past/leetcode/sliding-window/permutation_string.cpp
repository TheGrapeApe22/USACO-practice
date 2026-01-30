// https://leetcode.com/problems/permutation-in-string/
#include <bits/stdc++.h>
using namespace std;
/*
construct s1_freq
construct s2_freq
iterate s2
*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        if (n > s2.size()) return false;

        vector<int> s1_freq (26);
        for (char c : s1) s1_freq[c-'a']++;

        vector<int> s2_freq (26);
        for (int i = 0; i < n; i++) s2_freq[s2[i]-'a']++;

        for (int i = n; i < s2.size(); i++) {
            if (s1_freq == s2_freq) return true;
            s2_freq[s2[i - n] - 'a']--;
            s2_freq[s2[i] - 'a']++;
        }

        return s1_freq == s2_freq;
    }
};