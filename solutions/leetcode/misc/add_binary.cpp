// https://leetcode.com/problems/add-binary 2/14/26
/*
loop from right to left:
    calculate result, store carry
*/

class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size(), m = b.size();
        vector<char> reverse;
        int carry = 0;
        for (int i = 0; i < max(n, m); i++) {
            int d1 = 0;
            if (n-i-1 >= 0)
                d1 = a[n - i - 1] - '0';
            int d2 = 0;
            if (m-i-1 >= 0)
                d2 = b[m - i - 1] - '0';
            int sum = d1 + d2 + carry;
            // #define _ << " " <<
            // cout << d1 _ d2 _ sum << "\n";
            reverse.push_back('0' + (sum)%2);
            carry = (d1+d2+carry)/2;
        }
        if (carry) reverse.push_back('1');

        string ans;
        for (int i = (int)reverse.size() - 1; i >= 0; i--)
            ans += reverse[i];
        return ans;
    }
};
