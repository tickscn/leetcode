/*
 * @lc app=leetcode id=70 lang=c
 *
 * [70] Climbing Stairs
 */

int climbStairs(int n)
{
	if (n <= 3)
		return n;
	int ret[3] = {1, 2, 3};
	for (int i = 4; i <= n; ++i)
	{
		ret[(i - 1) % 3] = ret[(i - 2) % 3] + ret[i % 3];
	}
	return ret[(n - 1) % 3];
}
