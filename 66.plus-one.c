/*
 * @lc app=leetcode id=66 lang=c
 *
 * [66] Plus One
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize)
{
	int i;
	int* ret;
	for (i = 0; i < digitsSize; ++i)
	{
		if (digits[i] != 9)
			break;
	}
	if (i == digitsSize)
	{
		*returnSize = digitsSize + 1;
		ret = (int*)calloc(*returnSize, sizeof(int));
		ret[0] = 1;
		return ret;
	}
	else
	{
		*returnSize = digitsSize;
		ret = (int*)calloc(*returnSize, sizeof(int));
		int car = 1;
		for (int i = digitsSize - 1; i >= 0; --i)
		{
			ret[i] = (digits[i] + car) % 10;
			car = (digits[i] + car) / 10;
		}
		return ret;
	}
}
