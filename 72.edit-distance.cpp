/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */
class Solution
{
public:
	int minDistance(string word1, string word2)
	{
		int size1 = word1.size();
		int size2 = word2.size();
		if (size1 == 0 || size2 == 0) return size1 + size2;
		vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1));
		for (int i = 0; i <= size1; ++i)
		{
			dp[i][0] = i;
		}
		for (int j = 0; j <= size2; ++j)
		{
			dp[0][j] = j;
		}
		for (int i = 1; i <= size1; ++i)
		{
			for (int j = 1; j <= size2; ++j)
			{
				if (word1[i - 1] == word2[j - 1])
				{
					dp[i][j] = dp[i - 1][j - 1];
				}
				else
				{
					int tmp = dp[i - 1][j];
					if (dp[i][j - 1] < tmp) tmp = dp[i][j - 1];
					if (dp[i - 1][j - 1] < tmp) tmp = dp[i - 1][j - 1];
					dp[i][j] = tmp + 1;
				}
			}
		}
		return dp[size1][size2];
	}
};
