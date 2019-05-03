/*
 * @lc app=leetcode id=14 lang=c
 *
 * [14] Longest Common Prefix
 */

char* longestCommonPrefix(char** strs, int strsSize)
{
	if (!strsSize)
	{
		return "";
	}
	if (strsSize == 1)
	{
		return strs[0];
	}
	for (int j = 0;; ++j)
		for (int i = 0; i < strsSize - 1; ++i)
		{
			if (strs[i][j] == '\0')
				return strs[i];
			if (strs[i][j] != strs[i + 1][j])
			{
				strs[0][j] = '\0';
				return strs[0];
			}
		}
}
