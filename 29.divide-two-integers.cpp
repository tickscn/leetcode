/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */
#include <climits>
#include <cmath>
class Solution
{
public:
	int divide(int dividend, int divisor)
	{
		if (divisor == 0 || (dividend == INT_MIN && divisor == -1))
		{
			return INT_MAX;
		}
		if (divisor == 1 && dividend == INT_MIN) return INT_MIN;
		int res = 0;
		bool sign = true;
		if (dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0)
		{
			sign = false;
		}
		unsigned int undividend = dividend;
		unsigned int undivisor = divisor;
		if (undividend > INT_MAX) undividend = ~undividend + 1;
		if (undivisor > INT_MAX) undivisor = ~undivisor + 1;
		while (undividend >= undivisor)
		{
			int n = 1;
			unsigned int unTmp = undivisor;
			while (undividend >= unTmp)
			{
				undividend -= unTmp;
				res += n;
				if (unTmp < 1073741824)
				{
					unTmp <<= 1;
					n <<= 1;
				}
			}
		}
		return sign ? res : -res;
	}
};
