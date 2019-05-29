/*
 * @lc app=leetcode id=167 lang=c
 *
 * [167] Two Sum II - Input array is sorted
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
{
	int* ret = (int*)malloc(2 * sizeof(int));
	*returnSize = 2;
	ret[0] = 1;
	ret[1] = numbersSize;
	while (ret[0] < ret[1])
	{
		if (numbers[ret[0] - 1] + numbers[ret[1] - 1] == target)
			return ret;
		else if (numbers[ret[0] - 1] + numbers[ret[1] - 1] < target)
			++ret[0];
		else
			--ret[1];
	}
	return ret;
}
