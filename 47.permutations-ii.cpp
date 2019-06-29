/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */
class Solution
{
public:
	int size;
	void rePermute(vector<vector<int>>& res, vector<int>& out, int oSize, vector<int>& nums, vector<bool>& map)
	{
		if (oSize == size)
		{
			res.push_back(out);
			return;
		}
		for (int i = 0; i < size; ++i)
		{
			if (map[i]) continue;
			if (i > 0 && nums[i] == nums[i - 1] && !map[i - 1]) continue;
			out[oSize] = nums[i];
			map[i] = true;
			rePermute(res, out, oSize + 1, nums, map);
			map[i] = false;
		}
	}
	vector<vector<int>> permuteUnique(vector<int>& nums)
	{
		size = nums.size();
		vector<vector<int>> res;
		vector<int> out(size);
		vector<bool> map(size, false);
		sort(nums.begin(), nums.end());
		rePermute(res, out, 0, nums, map);
		return res;
	}
};
