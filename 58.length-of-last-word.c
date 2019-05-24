/*
 * @lc app=leetcode id=58 lang=c
 *
 * [58] Length of Last Word
 */

int lengthOfLastWord(char* s)
{
	int ret = 0;
	while (*s)
	{
		if (!isspace(*s))
		{
			++ret;
		}
		else if (*(s + 1) && !isspace(*(s + 1)))
		{
			ret = 0;
		}
		++s;
	}
	return ret;
}
