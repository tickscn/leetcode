/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
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
			if (i > start && candidates[i] == candidates[i - 1])
			{
				continue;
			}
			out.push_back(candidates[i]);
			combinationSumDFS(candidates, target - candidates[i], i + 1, out, res);
			out.pop_back();
		}
	}
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
	{

		sort(candidates.begin(), candidates.end());
		vector<vector<int>> res;
		vector<int> out;
		combinationSumDFS(candidates, target, 0, out, res);
		return res;
	}
};
