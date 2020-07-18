/*
 * @lc app=leetcode.cn id=991 lang=cpp
 *
 * [991] 坏了的计算器
 */

// @lc code=start
class Solution {
public:
    int brokenCalc(int X, int Y)
    {
        if (X >= Y) return X - Y;
        return Y & 1 ? 2 + brokenCalc(X, (Y + 1) / 2) : 1 + brokenCalc(X, Y / 2);
    }
};
// @lc code=end
