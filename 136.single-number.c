/*
 * @lc app=leetcode id=136 lang=c
 *
 * [136] Single Number
 */

int singleNumber(int* nums, int numsSize)
{
	int ret = nums[0];
	for (int i = 1; i < numsSize; ++i)
	{
		ret ^= nums[i];
	}

	return ret;
}
