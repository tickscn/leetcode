/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 */
class Solution
{
public:
	int numDistinct(string s, string t)
	{
		int sLength = s.length();
		int tLength = t.length();
		if (tLength == 0)
			return 1;
		else if (sLength == 0)
			return 0;
		vector<vector<unsigned int>> dp(tLength + 1, vector<unsigned int>(sLength + 1, 0));
		for (int i = 0; i <= sLength; ++i) dp[0][i] = 1;
		for (int i = 1; i <= tLength; ++i)
		{
			for (int j = 1; j <= sLength; ++j)
			{
				dp[i][j] = dp[i][j - 1] + (t[i - 1] == s[j - 1] ? dp[i - 1][j - 1] : 0);
			}
		}

		return dp[tLength][sLength];
	}
};
