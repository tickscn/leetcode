/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution {
public:
    bool charMatch(char c1, char c2)
    {
        return c1 == c2 || c2 == '.';
    }
    bool isMatch(string s, string p)
    {
        if (p.empty()) return s.empty();
        if (p.length() > 1 && p[1] == '*')
            return isMatch(s, p.substr(2)) || (!s.empty() && charMatch(s[0], p[0]) && isMatch(s.substr(1), p));
        else
            return !s.empty() && charMatch(s[0], p[0]) && isMatch(s.substr(1), p.substr(1));
    }
};
// @lc code=end
