/*
 * @lc app=leetcode id=87 lang=cpp
 *
 * [87] Scramble String
 */
class Solution
{
public:
	bool isScramble(string s1, string s2)
	{
		int length = s1.length();
		if (length != s2.length()) return false;
		if (s1 == s2) return true;
		vector<vector<vector<bool>>> dp(length, vector<vector<bool>>(length, vector<bool>(length)));
		for (int i = 0; i < length; ++i)
			for (int j = 0; j < length; ++j) dp[i][j][0] = s1[i] == s2[j];
		for (int len = 1; len < length; ++len)
			for (int i = 0; i < length - len; ++i)
				for (int j = 0; j < length - len; ++j)
					for (int k = 0; k < len; ++k)
						if (dp[i][j][k] && dp[i + k + 1][j + k + 1][len - k - 1] || dp[i][j + len - k][k] && dp[i + k + 1][j][len - k - 1])
						{
							dp[i][j][len] = true;
						}

		return dp[0][0][length - 1];
	}
};
