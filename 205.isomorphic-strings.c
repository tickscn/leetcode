/*
 * @lc app=leetcode id=205 lang=c
 *
 * [205] Isomorphic Strings
 */

bool isIsomorphic(char* s, char* t)
{
	char ch1[256] = {0};
	char ch2[256] = {0};
	for (int i = 0; s[i]; ++i)
	{
		if (!ch1[s[i]])
			ch1[s[i]] = t[i];
		else if (ch1[s[i]] != t[i])
			return false;
		if (!ch2[t[i]])
			ch2[t[i]] = s[i];
		else if (ch2[t[i]] != s[i])
			return false;
	}
	return true;
}
