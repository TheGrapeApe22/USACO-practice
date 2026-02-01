// https://leetcode.com/problems/longest-increasing-subsequence/
// WHY IS LINEAR SEARCH 1 ms BUT BINARY SEARCH 4 ms????
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lowest (n);
        int maxLen = 0;
        for (int x : nums) {
            // find leftmost index >= x
            int l = 0, r = maxLen;
            while (l < r) {
                int mid = (l+r)/2;
                if (lowest[mid] >= x)
                    r = mid;
                else
                    l = mid+1;
            }

            lowest[l] = x;
            if (l == maxLen) maxLen++;
        }
        return maxLen;
    }
};