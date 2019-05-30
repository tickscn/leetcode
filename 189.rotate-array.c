/*
 * @lc app=leetcode id=189 lang=c
 *
 * [189] Rotate Array
 */

void rotate(int* nums, int numsSize, int k)
{
	k %= numsSize;
	for (int i = 0, j = numsSize - k - 1; i < j; ++i, --j)
	{
		int tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
	}
	for (int i = numsSize - k, j = numsSize - 1; i < j; ++i, --j)
	{
		int tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
	}
	for (int i = 0, j = numsSize - 1; i < j; ++i, --j)
	{
		int tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
	}
}
