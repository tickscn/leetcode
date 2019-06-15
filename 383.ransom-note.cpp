/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */
class Solution
{
public:
	bool canConstruct(string ransomNote, string magazine)
	{
		int r[26] = {0}, m[26] = {0};
		for (int i = 0; i < ransomNote.length(); ++i)
		{
			++r[ransomNote[i] - 'a'];
		}
		for (int i = 0; i < magazine.length(); ++i)
		{
			++m[magazine[i] - 'a'];
		}
		for (int i = 0; i < 26; ++i)
		{
			if (r[i] > m[i]) return false;
		}
		return true;
	}
};
