/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n)
    {
        while (n % 4 == 0) n /= 4;
        if (n % 8 == 7) return 4;
        for (int i = 0; i * i <= n; ++i)
        {
            int j = n - i * i;
            if (j == 0) return 1;
            if (pow(static_cast<int>(sqrt(j)), 2) == j) return 1 + (i ? 1 : 0);
        }
        return 3;
    }
};
// @lc code=end
