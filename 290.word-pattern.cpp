/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 */
#include <string>
#include <unordered_map>
using std::string;
using std::unordered_map;
class Solution
{
public:
	bool wordPattern(string pattern, string str)
	{
		unordered_map<char, int> map_p;
		unordered_map<string, int> map_s;
		std::istringstream in(str);
		int i = 0, n = pattern.size();
		for (string parseword; in >> parseword; ++i)
		{
			if (i == n || map_p[pattern[i]] != map_s[parseword])
				return false;
			map_p[pattern[i]] = map_s[parseword] = i + 1;
		}
		return i == n;
	}
};
