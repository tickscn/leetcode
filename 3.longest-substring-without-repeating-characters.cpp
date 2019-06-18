/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */
#include <unordered_map>
using namespace std;
class Solution
{
public:
	int lengthOfLongestSubstring(string s)
	{
		unordered_map<char, int> table;
		int length = s.length();
		int res = 0;
		int l = 0;
		for (int i = 0; i < length; ++i)
		{
			if (table.count(s[i]))
			{
				l = l > table[s[i]] + 1 ? l : table[s[i]] + 1;
			}
			table[s[i]] = i;
			res = res > i - l + 1 ? res : i - l + 1;
		}
		return res;
	}
};
