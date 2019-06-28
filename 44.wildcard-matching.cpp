/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 */
class Solution
{
public:
	inline bool equalChar(char a, char b)
	{
		return a == b || b == '?';
	}
	bool isMatch(string s, string p)
	{
		int sLen = s.length();
		int pLen = p.length();
		vector<vector<bool>> dp(sLen + 1, vector<bool>(pLen + 1, false));
		dp[0][0] = true;
		for (int i = 1; i <= pLen; ++i)
		{
			dp[0][i] = (p[i - 1] == '*' && dp[0][i - 1]);
		}
		for (int i = 1; i <= sLen; ++i)
		{
			for (int j = 1; j <= pLen; ++j)
			{
				if (p[j - 1] == '*')
				{
					dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
				}
				else
				{
					dp[i][j] = dp[i - 1][j - 1] && equalChar(s[i - 1], p[j - 1]);
				}
			}
		}
		return dp[sLen][pLen];
	}
};
