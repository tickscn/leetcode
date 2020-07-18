/*
 * @lc app=leetcode.cn id=1247 lang=cpp
 *
 * [1247] 交换字符使得字符串相同
 */

// @lc code=start
class Solution {
public:
    int minimumSwap(string s1, string s2)
    {
        int len = s1.length();
        if (len == 0) return 0;
        int c1 = 0, c2 = 0;
        for (int i = 0; i < len; ++i)
        {
            if (s1[i] != s2[i])
            {
                if (s1[i] == 'x')
                    ++c1;
                else
                    ++c2;
            }
        }
        return (c1 + c2) % 2 ? -1 : (c1 + 1) / 2 + (c2 + 1) / 2;
    }
};
// @lc code=end
