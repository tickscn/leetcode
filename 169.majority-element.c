/*
 * @lc app=leetcode id=169 lang=c
 *
 * [169] Majority Element
 */

int majorityElement(int* nums, int numsSize)
{
	int count = 1;
	int retIndex = 0;
	for (int i = 1; i < numsSize; ++i)
	{
		if (nums[i] == nums[retIndex])
		{
			retIndex = i;
			++count;
		}
		else
		{
			if (count == 1)
				++retIndex;
			else
				--count;
		}
	}
	return nums[retIndex];
}
