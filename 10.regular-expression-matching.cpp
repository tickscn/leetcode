/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */
class Solution
{
public:
	inline bool equalChar(char a, char b)
	{
		return a == b || b == '.';
	}
	bool isMatch(string s, string p)
	{
		if (p.empty()) return s.empty();
		if (p.length() > 1 && p[1] == '*')
		{
			return isMatch(s, p.substr(2)) || (!s.empty() && equalChar(s[0], p[0]) && isMatch(s.substr(1), p));
		}
		else
			return !s.empty() && equalChar(s[0], p[0]) && isMatch(s.substr(1), p.substr(1));
	}
};
