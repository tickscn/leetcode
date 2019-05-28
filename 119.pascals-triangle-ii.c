/*
 * @lc app=leetcode id=119 lang=c
 *
 * [119] Pascal's Triangle II
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdbool.h>
int* getRow(int rowIndex, int* returnSize)
{
	*returnSize = rowIndex + 1;
	int* returnArray = (int*)malloc(*returnSize * sizeof(int));
	*returnArray = 1;
	if (rowIndex == 0)
		return returnArray;
	returnArray[1] = 1;
	if (rowIndex == 1)
		return returnArray;
	int tmp[2];
	for (int i = 2; i <= rowIndex; ++i)
	{
		tmp[0] = returnArray[0];
		tmp[1] = returnArray[1];
		for (int j = 1; j < i + 1; ++j)
		{
			if (j == i)
				returnArray[j] = 1;
			else
			{
				returnArray[j] = tmp[0] + tmp[1];
				tmp[(j + 1) % 2] = returnArray[j + 1];
			}
		}
	}
	return returnArray;
}
