/*
 * @lc app=leetcode id=198 lang=c
 *
 * [198] House Robber
 */
int max(int a, int b)
{
	return a > b ? a : b;
}
int rob(int* nums, int numsSize)
{
	if (numsSize == 0)
		return 0;
	if (numsSize == 1)
		return *nums;
	if (numsSize == 2)
		return max(nums[0], nums[1]);
	int* dp = (int*)malloc(sizeof(int) * numsSize);
	dp[0] = nums[0];
	dp[1] = max(nums[0], nums[1]);
	for (int i = 2; i < numsSize; ++i)
	{
		dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
	}

	return dp[numsSize - 1];
}
