/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */
class Solution
{
public:
	int jump(vector<int>& nums)
	{
		int stepNum = 0;
		int size = nums.size();
		int cur = 0;
		int farest = 0;
		for (int i = 0; i < size; ++i)
		{
			if (i > farest)
			{
				farest = cur;
				++stepNum;
			}
			cur = cur > i + nums[i] ? cur : i + nums[i];
		}
		return stepNum;
	}
};
