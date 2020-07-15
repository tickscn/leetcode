/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i)
        {
            int MIN = INT_MAX;
            for (int coin : coins)
            {
                if (i - coin >= 0 && dp[i - coin] >= 0) MIN = min(MIN, dp[i - coin]);
            }
            if (MIN != INT_MAX) dp[i] = MIN + 1;
        }
        return dp[amount];
    }
};
// @lc code=end
