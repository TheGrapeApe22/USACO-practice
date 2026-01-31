// https://leetcode.com/problems/largest-rectangle-in-histogram/
#include <bits/stdc++.h>
using namespace std;

struct bar {
    int height;
    int index;
};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<bar> st;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int h = heights[i];
            int newI = i;
            while (!st.empty() && st.top().height >= h) {
                newI = st.top().index;
                ans = max(ans, st.top().height * (i - st.top().index));
                st.pop();
            }
            st.push({h, newI});
        }
        while (!st.empty()) {
            ans = max(ans, st.top().height * (n - st.top().index));
            st.pop();
        }
        return ans;
    }
};