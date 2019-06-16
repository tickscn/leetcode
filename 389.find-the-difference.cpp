/*
 * @lc app=leetcode id=389 lang=cpp
 *
 * [389] Find the Difference
 */
class Solution
{
public:
	char findTheDifference(string s, string t)
	{
		/* 建表 */
		//	char sch[26] = {0}, tch[26] = {0};
		//	for (int i = 0; i < s.length(); ++i)
		//	{
		//		++sch[s[i] - 'a'];
		//	}
		//	for (int i = 0; i < t.length(); ++i)
		//	{
		//      ++tch[t[i] - 'a'];
		//	}
		//	for (int i = 0; i < 26; ++i)
		//	{
		//		if (tch[i] - sch[i] == 1) return 'a' + i;
		//	}
		//	return t[0];
		/* 位运算 */
		char ret = 0;
		for (char a : s)
		{
			ret ^= a;
		}
		for (char a : t)
		{
			ret ^= a;
		}
		return ret;
	}
};
