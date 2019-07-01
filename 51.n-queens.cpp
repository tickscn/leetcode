/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */
class Solution
{
public:
	void updateRes(vector<vector<string>>& res, vector<int>& queen, int n)
	{
		vector<string> tmp(n, string(n, '.'));
		for (int i = 0; i < n; ++i)
		{
			tmp[i][queen[i]] = 'Q';
		}
		res.push_back(tmp);
	}
	bool isValid(vector<int>& queen, int n, int j)
	{
		for (int i = 0; i < n; ++i)
		{
			if (queen[i] == j) return false;
			if (n - i == abs(queen[i] - j)) return false;
		}
		return true;
	}
	void reQueens(vector<vector<string>>& res, vector<int>& queen, int i, int n)
	{
		if (i == n)
		{
			updateRes(res, queen, n);
			return;
		}
		for (int j = 0; j < n; ++j)
		{
			if (isValid(queen, i, j))
			{
				queen[i] = j;
				reQueens(res, queen, i + 1, n);
			}
		}
	}
	vector<vector<string>> solveNQueens(int n)
	{
		vector<vector<string>> res;
		vector<int> queen(n);
		reQueens(res, queen, 0, n);
		return res;
	}
};
