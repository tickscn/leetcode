/*
 * @lc app=leetcode id=26 lang=c
 *
 * [26] Remove Duplicates from Sorted Array
 */

int removeDuplicates(int* nums, int numsSize)
{
	if (!numsSize)
		return 0;
	int i = 0, j = 1;
	while (1)
	{
		while (j < numsSize && nums[i] == nums[j])
		{
			++j;
		}
		if (j == numsSize)
			break;
		nums[i + 1] = nums[j];
		++i;
		++j;
	}
	return i + 1;
}
