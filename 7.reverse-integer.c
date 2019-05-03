/*
 * @lc app=leetcode id=7 lang=c
 *
 * [7] Reverse Integer
 */

int reverse(int x)
{
	int ret = 0;
	int dig;
	while (x != 0)
	{
		dig = x % 10;
		x /= 10;
		if (ret > 214748364 || (ret == 214748364 && dig > 7))
			return 0;
		if (ret < -214748364 || (ret == -214748364 && dig < -8))
			return 0;
		ret = ret * 10 + dig;
	}
	return ret;
}
