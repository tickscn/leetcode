/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */
class Solution
{
public:
	int firstUniqChar(string s)
	{
		int table[26] = {0};
		for (char ch : s) ++table[ch - 'a'];
		for (int i = 0; i < s.length(); ++i)
		{
			if (table[s[i] - 'a'] == 1) return i;
		}
		return -1;
	}
};
