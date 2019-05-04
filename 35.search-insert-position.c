/*
 * @lc app=leetcode id=35 lang=c
 *
 * [35] Search Insert Position
 */

int searchInsert(int* nums, int numsSize, int target)
{
	int i = 0, j = numsSize - 1, mid;
	while (i != j)
	{
		mid = (i + j) / 2;
		if (target == nums[mid])
			return mid;
		if (target < nums[mid])
			j = mid;
		else
		{
			i = mid + 1;
		}
	}
	if (target > nums[i])
		++i;
	return i;
}
