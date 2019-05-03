/*
 * @lc app=leetcode id=27 lang=c
 *
 * [27] Remove Element
 */

int removeElement(int* nums, int numsSize, int val)
{
	for (int i = 0; i < numsSize;)
	{
		if (nums[i] == val)
		{
			nums[i] = nums[--numsSize];
		}
		else
		{
			++i;
		}
	}
	return numsSize;
}
