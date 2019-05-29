/*
 * @lc app=leetcode id=171 lang=c
 *
 * [171] Excel Sheet Column Number
 */

int titleToNumber(char* s)
{
	int ret = 0;
	int length = strlen(s);
	for (int i = 0, j = length - 1; i < length; ++i, --j)
	{
		ret += (s[i] - 'A' + 1) * pow(26, j);
	}
	return ret;
}
