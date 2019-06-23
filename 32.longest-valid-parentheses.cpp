/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */
#include <vector>
using namespace std;
class Solution
{
public:
	int longestValidParentheses(string s)
	{
		int size = s.size();
		if (size < 2) return 0;
		vector<int> dp(size, 0);
		int max_len = 0;
		for (int i = 1; i < size; ++i)
		{
			if (s[i] == ')')
			{
				if (s[i - 1] == '(')
				{
					dp[i] = (i >= 2) ? dp[i - 2] + 2 : 2;
					max_len = max_len > dp[i] ? max_len : dp[i];
				}
				else
				{
					if ((i - 1 - dp[i - 1]) >= 0 && s[i - 1 - dp[i - 1]] == '(')
					{
						dp[i] = dp[i - 1] + 2 + ((i - 1 - dp[i - 1] >= 2) ? dp[i - 2 - dp[i - 1]] : 0);
						max_len = max_len > dp[i] ? max_len : dp[i];
					}
				}
			}
		}
		return max_len;
	}
};
