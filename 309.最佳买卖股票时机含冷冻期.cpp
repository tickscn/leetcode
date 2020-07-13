/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        size_t size = prices.size();
        if (size < 2) return 0;
        unique_ptr<int[]> hold(new int[size]);
        unique_ptr<int[]> noHold(new int[size]);
        hold[0]   = -prices[0];
        noHold[0] = 0;
        hold[1]   = max(-prices[0], -prices[1]);
        noHold[1] = max(0, prices[1] - prices[0]);
        for (int i = 2; i < size; ++i)
        {
            hold[i]   = max(hold[i - 1], noHold[i - 2] - prices[i]);
            noHold[i] = max(noHold[i - 1], hold[i - 1] + prices[i]);
        }
        return noHold[size - 1];
    }
};
// @lc code=end
