/*
 * @lc app=leetcode id=400 lang=cpp
 *
 * [400] Nth Digit
 */
#include <string>
using namespace std;
class Solution
{
public:
	int findNthDigit(int n)
	{
		int len = 1;  //位数
		int base = 1;
		while (n > 9L * len * base)
		{
			n -= 9 * len * base;
			base *= 10;
			++len;
		}
		int tmp = base + (n - 1) / len;
		len = (n - 1) % len;
		return to_string(tmp)[len] - '0';
	}
};
