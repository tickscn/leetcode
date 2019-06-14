/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */
class Solution
{
public:
	void reverseString(vector<char>& s)
	{
		for (int i = 0, j = s.size() - 1; i < j; ++i, --j)
		{
			char tmp = s[j];
			s[j] = s[i];
			s[i] = tmp;
		}
	}
};
