/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
	string longestPalindrome(string s)
	{
		if (s.empty()) return "";
		int length = s.length();
		if (length == 1) return s;
		bool** dp = new bool*[length];
		for (int i = 0; i < length; ++i)
		{
			dp[i] = new bool[length - i]{false};
		}
		int l = 1;
		int index = 0;
		for (int len = 0; len < length; ++len)
		{
			for (int i = 0; i + len < length; ++i)
			{
				if (len == 0)
				{
					dp[i][len] = true;
				}
				else if (len == 1)
				{
					if (s[i] == s[i + len])
					{
						l = 2;
						index = i;
						dp[i][len] = true;
					}
				}
				else
				{
					if (s[i] == s[i + len] && dp[i + 1][len - 2])
					{
						l = len + 1;
						index = i;
						dp[i][len] = true;
					}
				}
			}
		}
		return s.substr(index, l);
	}
};
