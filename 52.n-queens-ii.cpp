/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 */
class Solution
{
public:
	int resNum = 0;
	bool isValid(vector<int>& queen, int n, int j)
	{
		for (int i = 0; i < n; ++i)
		{
			if (queen[i] == j) return false;
			if (n - i == abs(queen[i] - j)) return false;
		}
		return true;
	}
	void reQueens(vector<int>& queen, int i, int n)
	{
		if (i == n)
		{
			++resNum;
			return;
		}
		for (int j = 0; j < n; ++j)
		{
			if (isValid(queen, i, j))
			{
				queen[i] = j;
				reQueens(queen, i + 1, n);
			}
		}
	}
	int totalNQueens(int n)
	{
		vector<int> queen(n);
		reQueens(queen, 0, n);
		return resNum;
	}
};
