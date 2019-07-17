/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
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
			while (j + 1 < nums.size() && nums[j] == nums[j + 1]) ++j;
		}
	}
	vector<vector<int>> subsetsWithDup(vector<int>& nums)
	{
		vector<vector<int>> ret;
		vector<int> tmp;
		sort(nums.begin(), nums.end());
		dfs(ret, nums, tmp, 0);
		return ret;
	}
};
