// https://leetcode.com/problems/minimum-window-substring/
#include <bits/stdc++.h>
using namespace std;
/*
construct freq_t
helper function works(freq) -> returns if freq contains freq_t
l=0, r=0
loop:
    move r right until [l, r] works
    move l right until [l, r] doesn't work, tracking [l, r] as ans
*/
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        // construct freq_t
        map<char, int> freq_t;
        for (char c : t) {
            freq_t[c]++;
        }

        map<char, int> freq;
        // helper function works(freq) -> returns if freq contains freq_t
        auto works = [&]() {
            for (char c = 'a'; c <= 'z'; c++) {
                if (freq_t[c] > freq[c]) return false;
            }
            for (char c = 'A'; c <= 'Z'; c++) {
                if (freq_t[c] > freq[c]) return false;
            }
            return true;
        };

        // l=0 (inclusive), r=0 (exclusive)
        int l = 0, r = 0;
        int ans_l = -1, ans_r = -1;

        // loop:
        while (true) {
            // move r right until [l, r) works
            while (r < n && !works()) {
                freq[s[r]]++;
                r++;
            }
            
            if (!works()) break;
            
            // move l right until [l, r) doesn't work, tracking [l, r) as ans
            while (l < n && works()) {
                if (r-l < ans_r - ans_l || ans_l == -1) {
                    ans_l = l;
                    ans_r = r;
                }
                freq[s[l]]--;
                l++;
            }
            // if l out of bounds, return
            if (l >= n) break;
        }
        if (ans_l == -1) return "";
        return s.substr(ans_l, ans_r - ans_l);
    }
};