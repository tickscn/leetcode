/*
 * @lc app=leetcode id=434 lang=cpp
 *
 * [434] Number of Segments in a String
 */
class Solution
{
public:
	int countSegments(string s)
	{
		int ret = 0;
		if (s.length() == 0) return ret;
		bool inSegm = false;
		for (char ch : s)
		{
			if (!isblank(ch) && !inSegm)
			{
				++ret;
				inSegm = true;
			}
			else if (isblank(ch))
			{
				inSegm = false;
			}
		}
		return ret;
	}
};
