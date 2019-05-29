/*
 * @lc app=leetcode id=122 lang=c
 *
 * [122] Best Time to Buy and Sell Stock II
 */

int maxProfit(int* prices, int pricesSize)
{
	if (pricesSize <= 1)
		return 0;
	int ret = 0;
	int a;
	for (int i = 0; i < pricesSize - 1; ++i)
	{
		a = prices[i + 1] - prices[i];
		if (a > 0)
			ret += a;
	}
	return ret;
}
