/*
 * @lc app=leetcode id=123 lang=c
 *
 * [123] Best Time to Buy and Sell Stock III
 */

// @lc code=start
#include <limits.h>
int sellProfit(int* prices, int pricesSize)
{
    int sell1 = 0;
    int buy1  = INT_MAX;
    int sell2 = 0;
    int buy2  = INT_MAX;
    for (int i = 0; i < pricesSize; i++)
    {
        sell1 = prices[i] - buy1 > buy1 ? prices[i] - buy1 : sell1;
        buy1  = prices[i] < buy1 ? prices[i] : buy1;
        sell2 = prices[i] - buy2 > sell2 ? prices[i] - buy2 : sell2;
        buy2  = prices[i] - sell1 < buy2 ? prices[i] - sell1 : buy2;
    }
    return sell2;
}

// @lc code=end
