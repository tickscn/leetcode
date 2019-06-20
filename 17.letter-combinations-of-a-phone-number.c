/*
 * @lc app=leetcode id=17 lang=c
 *
 * [17] Letter Combinations of a Phone Number
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

char** letterCombinations(char* digits, int* returnSize)
{
	char** ret = NULL;
	char map[10][5] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	*returnSize = 1;
	int length = 0;
	while (digits[length])
	{
		if (digits[length] == '7' || digits[length] == '9')
			(*returnSize) *= 4;
		else
			(*returnSize) *= 3;
		++length;
	}
	if (length == 0)
	{
		*returnSize = 0;
		return ret;
	}
	ret = (char**)malloc((*returnSize) * sizeof(char*));
	for (int i = 0; i < *returnSize; ++i)
	{
		ret[i] = (char*)malloc(length + 1);
		ret[i][length] = '\0';
	}
	for (int j = 0, loopSize = 1; j < length; ++j)
	{
		int size = (digits[j] == '7' || digits[j] == '9') ? 4 : 3;
		for (int i = 0; i < *returnSize; ++i)
		{
			ret[i][j] = map[digits[j] - '0'][i / loopSize % size];
		}
		loopSize *= size;
	}
	return ret;
}
