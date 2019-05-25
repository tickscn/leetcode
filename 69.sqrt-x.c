/*
 * @lc app=leetcode id=69 lang=c
 *
 * [69] Sqrt(x)
 */

int mySqrt(int x)
{
	if (x < 1)
		return 0;
	if (x < 4)
		return 1;
	unsigned int left = 0, right = x, mid;
	if (x > 2 << 16)
	{
		right = 2 << 16 - 1;
	}
	mid = left + (right - left) / 2;
	while (!(mid * mid == x || (mid * mid < x && (mid + 1) * (mid + 1) > x)))
	{
		if (mid * mid > x)
		{
			right = mid;
		}
		else
		{
			left = mid;
		}
		mid = left + (right - left) / 2;
	}
	return mid;
}
