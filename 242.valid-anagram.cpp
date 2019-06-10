/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */
#include <string>
using namespace std;
class Solution
{
public:
	bool isAnagram(string s, string t)
	{
		if (s.size() != t.size())
			return false;
		int snum[26] = {0}, tnum[26] = {0};
		for (int i = 0; i < s.size(); ++i)
		{
			snum[s[i] - 'a']++;
			tnum[t[i] - 'a']++;
		}
		for (int i = 0; i < 26; ++i)
		{
			if (snum[i] != tnum[i])
				return false;
		}
		return true;
	}
};
