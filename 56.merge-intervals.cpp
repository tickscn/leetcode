/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */
class Solution
{
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals)
	{
		int size = intervals.size();
		if (size == 0) return {};
		sort(intervals.begin(), intervals.end());
		vector<vector<int>> res{intervals[0]};
		for (int i = 1; i < size; ++i)
		{
			if (res.back()[1] < intervals[i][0])
			{
				res.push_back(intervals[i]);
			}
			else
			{
				res.back()[1] = max(res.back()[1], intervals[i][1]);
			}
		}
		return res;
	}
};
