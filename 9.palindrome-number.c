/*
 * @lc app=leetcode id=9 lang=c
 *
 * [9] Palindrome Number
 */

#include <stdbool.h>
bool isPalindrome(int x)
{
	if (x < 0 || (x != 0 && x % 10 == 0))
		return false;
	int inv = 0;
	int dig;
	int tmp = x;
	while (x != 0)
	{
		dig = x % 10;
		x /= 10;
		if (inv > 214748364 || (inv == 214748364 && dig > 7))
			return 0;
		if (inv < -214748364 || (inv == -214748364 && dig < -8))
			return 0;
		inv = inv * 10 + dig;
	}
	return inv == tmp;
}
