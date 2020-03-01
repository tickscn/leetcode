/*
 * @lc app=leetcode id=123 lang=c
 *
 * [123] Best Time to Buy and Sell Stock III
 */

// @lc code=start
int helper(int* prices, int pricesSize)
{
    if (pricesSize <= 1) return 0;
    int max = 0;
    int min = prices[0];
    for (int i = 1; i < pricesSize; ++i)
    {
        min = prices[i] < min ? prices[i] : min;
        max = prices[i] - min > max ? prices[i] - min : max;
    }
    return max;
}
int maxProfit(int* prices, int pricesSize)
{
    int ret = 0;
    for (int i = 0; i < pricesSize - 1; i++)
    {
        int a = helper(prices, i + 1) + helper(prices + i, pricesSize - i);
        if (a > ret) ret = a;
    }
    return ret;
}

// @lc code=end
