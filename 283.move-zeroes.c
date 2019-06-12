/*
 * @lc app=leetcode id=283 lang=c
 *
 * [283] Move Zeroes
 */

void swap(int* a, int* b)
{
	if (a == b)
		return;
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void moveZeroes(int* nums, int numsSize)
{
	for (int i = 0, j = 0; i < numsSize; ++i)
	{
		if (nums[i])
		{
			swap(nums + i, nums + j);
			++j;
		}
	}
}
