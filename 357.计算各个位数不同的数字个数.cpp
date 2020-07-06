/*
 * @lc app=leetcode.cn id=357 lang=cpp
 *
 * [357] 计算各个位数不同的数字个数
 */

// @lc code=start
class Solution {
public:
    int countNumbersWithUniqueDigits(int n)
    {
        if (n == 0) return 1;
        if (n == 1) return 10;
        int a1 = 1, a2 = 10, res;
        for (int i = 2; i <= n && i < 10; ++i)
        {
            res = a2 + (a2 - a1) * (11 - i);
            a1  = a2;
            a2  = res;
        }
        return res;
    }
};
// @lc code=end
