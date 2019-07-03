/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */
class Solution
{
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
	{
		int size = intervals.size();
		if (size == 0) return vector<vector<int>>{newInterval};
		bool isinsert = false;
		vector<vector<int>> res;
		int i = 1;
		if (newInterval[0] < intervals[0][0])
		{
			res.push_back(newInterval);
			i = 0;
			isinsert = true;
		}
		else
		{
			res.push_back(intervals[0]);
		}

		while (i < size)
		{
			if (isinsert || newInterval[0] > intervals[i][0])
			{
				if (res.back()[1] < intervals[i][0])
				{
					res.push_back(intervals[i]);
				}
				else
				{
					res.back()[1] = max(res.back()[1], intervals[i][1]);
				}
				++i;
			}
			else
			{
				if (res.back()[1] < newInterval[0])
				{
					res.push_back(newInterval);
				}
				else
				{
					res.back()[1] = max(res.back()[1], newInterval[1]);
				}
				isinsert = true;
			}
		}
		if (!isinsert)
		{
			if (res.back()[1] < newInterval[0])
			{
				res.push_back(newInterval);
			}
			else
			{
				res.back()[1] = max(res.back()[1], newInterval[1]);
			}
			isinsert = true;
		}
		return res;
	}
};
