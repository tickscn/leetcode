/*
 * @lc app=leetcode.cn id=1433 lang=cpp
 *
 * [1433] 检查一个字符串是否可以打破另一个字符串
 */

// @lc code=start
class Solution {
public:
    bool checkIfCanBreak(string s1, string s2)
    {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        int count1 = 0, count2 = 0;
        for (int i = 0; i < s1.length(); ++i)
        {
            if (s1[i] >= s2[i]) ++count1;
            if (s1[i] <= s2[i]) ++count2;
        }
        return count1 == s1.length() || count2 == s1.length();
    }
};
// @lc code=end
