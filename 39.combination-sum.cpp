/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */
class Solution
{
public:
	void combinationSumDFS(vector<int>& candidates, int target, int start, vector<int>& out, vector<vector<int>>& res)
	{
		if (target < 0) return;
		if (target == 0)
		{
			res.push_back(out);
			return;
		}
		for (int i = start; i < candidates.size(); ++i)
		{
			out.push_back(candidates[i]);
			combinationSumDFS(candidates, target - candidates[i], i, out, res);
			out.pop_back();
		}
	}
	vector<vector<int>> combinationSum(vector<int>& candidates, int target)
	{
		vector<vector<int>> res;
		vector<int> out;
		combinationSumDFS(candidates, target, 0, out, res);
		return res;
	}
};
