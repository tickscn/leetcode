/*
 * @lc app=leetcode id=118 lang=c
 *
 * [118] Pascal's Triangle
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes)
{
	*returnSize = numRows;
	int** ret = (int**)malloc(numRows * sizeof(int*));
	*returnColumnSizes = (int*)malloc(sizeof(int) * numRows);
	for (int i = 0; i < numRows; ++i)
	{
		(*returnColumnSizes)[i] = i + 1;
		ret[i] = (int*)malloc((i + 1) * sizeof(int));
		for (int j = 0; j < i + 1; ++j)
		{
			if (j == 0 || j == i)
				ret[i][j] = 1;
			else
			{
				ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
			}
		}
	}
	return ret;
}
