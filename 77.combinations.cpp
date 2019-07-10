/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */
class Solution
{
public:
	void recursion(vector<vector<int>>& res, vector<int>& tmp, int i, int n, int k)
	{
		if (tmp.size() == k)
		{
			res.push_back(tmp);
			return;
		}
		while (i <= n)
		{
			tmp.push_back(i);
			recursion(res, tmp, i + 1, n, k);
			tmp.pop_back();
			++i;
		}
	}
	vector<vector<int>> combine(int n, int k)
	{
		if (n < 1 || k > n) return {};
		vector<vector<int>> res;
		vector<int> tmp;
		recursion(res, tmp, 1, n, k);
		return res;
	}
};
