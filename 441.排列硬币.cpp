/*
 * @lc app=leetcode.cn id=441 lang=cpp
 *
 * [441] 排列硬币
 */

// @lc code=start
class Solution {
public:
    int arrangeCoins(int n)
    {
        double delta = sqrt(1 + 8L * n);
        return (int)(delta - 1) / 2;
    }
};
// @lc code=end
