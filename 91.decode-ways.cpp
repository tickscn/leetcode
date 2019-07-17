/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */
class Solution
{
public:
	bool is1To26(char c1, char c2)
	{
		return c1 == '1' || c1 == '2' && c2 < '7';
	}
	int numDecodings(string s)
	{
		int length = s.length();
		if (length == 0) return 0;
		if (length == 1) return s[0] == '0' ? 0 : 1;
		vector<int> dp(length, 0);
		if (s[0] == '0') return 0;
		dp[0] = 1;
		if (s[1] != '0') dp[1] = 1;
		if (is1To26(s[0], s[1])) ++dp[1];
		for (int i = 2; i < length; ++i)
		{
			if (s[i] != '0') dp[i] = dp[i - 1];
			if (is1To26(s[i - 1], s[i])) dp[i] += dp[i - 2];
		}
		return dp[length - 1];
	}
};
