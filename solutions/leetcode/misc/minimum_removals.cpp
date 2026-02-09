// https://leetcode.com/problems/minimum-removals-to-balance-array/description/?envType=daily-question&envId=2026-02-09
// could have used sliding window, but did binsearch instead
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int ans = nums.size() - 1;
        for (int i = 0; i < nums.size(); i++) {
            int l = 0, r = nums.size() - 1;
            while (l < r) {
                int mid = (l+r+1)/2;
                if (nums[mid] <= (long long)nums[i]*k)
                    l = mid;
                else
                    r = mid - 1;
            }
            
            ans = min(ans, (int)nums.size() - l - 1 + i);
        }
        
        return ans;
    }
};
