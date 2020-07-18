/*
 * @lc app=leetcode.cn id=678 lang=cpp
 *
 * [678] 有效的括号字符串
 */

// @lc code=start
class Solution {
public:
    bool checkValidString(string s)
    {
        int count = 0, sCount = 0;
        for (char ch : s)
        {
            if (ch == '*')
            {
                ++sCount;
            }
            else if (ch == '(')
            {
                ++count;
            }
            else
            {
                if (count)
                {
                    --count;
                }
                else if (sCount)
                    --sCount;
                else
                    return false;
            }
        }
        count  = 0;
        sCount = 0;
        for (auto it = s.rbegin(); it != s.rend(); ++it)
        {
            if (*it == '*')
            {
                ++sCount;
            }
            else if (*it == ')')
            {
                ++count;
            }
            else
            {
                if (count)
                {
                    --count;
                }
                else if (sCount)
                    --sCount;
                else
                    return false;
            }
        }
        return true;
    }
};
// @lc code=end
