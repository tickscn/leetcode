/*
 * @lc app=leetcode id=268 lang=c
 *
 * [268] Missing Number
 */

int missingNumber(int* nums, int numsSize)
{
	int ret = numsSize * (numsSize + 1) / 2;
	for (int i = 0; i < numsSize; ++i)
	{
		ret -= nums[i];
	}
	return ret;
}
