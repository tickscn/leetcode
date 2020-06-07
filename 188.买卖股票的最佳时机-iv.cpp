/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 *
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/description/
 *
 * algorithms
 * Hard (29.63%)
 * Likes:    221
 * Dislikes: 0
 * Total Accepted:    20.2K
 * Total Submissions: 68.1K
 * Testcase Example:  '2\n[2,4,1]'
 *
 * 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
 *
 * 设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。
 *
 * 注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 *
 * 示例 1:
 *
 * 输入: [2,4,1], k = 2
 * 输出: 2
 * 解释: 在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。
 *
 *
 * 示例 2:
 *
 * 输入: [3,2,6,5,0,3], k = 2
 * 输出: 7
 * 解释: 在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4
 * 。
 * 随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 。
 *
 *
 */

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices)
    {
        if (k < 1 || prices.size() < 2) return 0;
        if (k > prices.size() / 2) return greedy(prices);
        vector<pair<int, int>> dp(k, make_pair(INT_MIN, 0));
        for (int p : prices)
        {
            dp[0].first  = max(dp[0].first, -p);
            dp[0].second = max(dp[0].second, dp[0].first + p);
            for (int i = 1; i < k; ++i)
            {
                dp[i].first  = max(dp[i].first, dp[i - 1].second - p);
                dp[i].second = max(dp[i].second, dp[i].first + p);
            }
        }
        return dp[k - 1].second;
    }
    int greedy(vector<int>& p)
    {
        int res = 0;
        for (int i = 1; i < p.size(); ++i)
            if (p[i] > p[i - 1]) res += p[i] - p[i - 1];
        return res;
    }
};
// @lc code=end
