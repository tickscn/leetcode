/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
class Solution
{
public:
	int fib(int N)
	{
		int dp[3] = {0, 1, 1};
		for (int i = 3; i <= N; ++i) dp[i % 3] = dp[(i + 1) % 3] + dp[(i + 2) % 3];
		return dp[N % 3];
	}
};
// @lc code=end
