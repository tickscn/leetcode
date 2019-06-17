/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 */
class Solution
{
public:
	int longestPalindrome(string s)
	{
		int chlow[26] = {0}, chhigh[26] = {0};
		int ret = 0;
		for (char ch : s)
		{
			if (ch >= 'a' && ch <= 'z')
				++chlow[ch - 'a'];
			else
				++chhigh[ch - 'A'];
		}
		for (int i = 0; i < 26; ++i)
		{
			ret += chlow[i] / 2;
			ret += chhigh[i] / 2;
		}
		return s.length() == 2 * ret ? 2 * ret : 2 * ret + 1;
	}
};
