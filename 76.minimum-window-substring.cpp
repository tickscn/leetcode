/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */
class Solution
{
public:
	string minWindow(string s, string t)
	{
		int tSize = t.size();
		int sSize = s.size();
		int charCount[128]{0};
		int left = 0, minleft, minLen = INT_MAX, count = 0;
		for (char ch : t) ++charCount[ch];
		for (int right = 0; right < sSize; ++right)
		{
			if (charCount[s[right]]-- > 0) ++count;
			while (count == tSize)
			{
				if (right - left + 1 < minLen)
				{
					minLen  = right - left + 1;
					minleft = left;
				}
				if (++charCount[s[left]] > 0) --count;
				++left;
			}
		}
		return minLen == INT_MAX ? "" : s.substr(minleft, minLen);
	}
};
