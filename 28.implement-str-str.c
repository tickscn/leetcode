/*
 * @lc app=leetcode id=28 lang=c
 *
 * [28] Implement strStr()
 */

int strStr(char* haystack, char* needle)
{
	if (*needle == '\0')
		return 0;
	int ned_length = strlen(needle);
	int sta_length = strlen(haystack) - ned_length;
	for (int i = 0; i <= sta_length; i++)
	{
		if (strncmp(haystack + i, needle, ned_length) == 0)
			return i;
	}
	return -1;
}
