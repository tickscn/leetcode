/*
 * @lc app=leetcode id=231 lang=c
 *
 * [231] Power of Two
 */

bool isPowerOfTwo(int n)
{
	if (n <= 0)
		return false;
	int count = 0;
	for (int i = 0; i < 31; ++i)
	{
		if (n & 1 << i)
		{
			++count;
		}
		if (count > 1)
			return false;
	}
	return true;
}
