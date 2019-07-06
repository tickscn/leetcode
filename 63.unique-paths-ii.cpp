/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */
class Solution
{
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
	{
		if (obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0] == 1) return 0;
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		vector<long> dp(n, 0);
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (obstacleGrid[i][j] == 1)
					dp[j] = 0;
				else if (i == 0 && j == 0)
					dp[j] = 1;
				else if (i == 0 && dp[j - 1] != 0)
					dp[j] = 1;
				else if (j == 0)
					dp[0] = dp[0] && true;
				else
					dp[j] = dp[j] + dp[j - 1];
			}
		}
		return dp[n - 1];
	}
};
