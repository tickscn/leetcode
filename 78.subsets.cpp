/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */
class Solution
{
public:
	void dfs(vector<vector<int>>& res, vector<int>& nums, vector<int>& tmp, int i)
	{
		res.push_back(tmp);
		for (int j = i; j < nums.size(); ++j)
		{
			tmp.push_back(nums[j]);
			dfs(res, nums, tmp, j + 1);
			tmp.pop_back();
		}
	}
	vector<vector<int>> subsets(vector<int>& nums)
	{
		vector<vector<int>> ret;
		vector<int> tmp;
		dfs(ret, nums, tmp, 0);
		return ret;
	}
};
