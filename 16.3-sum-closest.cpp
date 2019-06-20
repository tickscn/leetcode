/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */
class Solution
{
public:
	int threeSumClosest(vector<int>& nums, int target)
	{
		int diff, ret;
		int size = nums.size();
		sort(nums.begin(), nums.end());
		ret = nums[0] + nums[1] + nums[size - 1];
		diff = abs(ret - target);
		for (int i = 0; i < size - 2; ++i)
		{
			int j = i + 1;
			int k = size - 1;
			while (j < k)
			{
				int tmp = nums[i] + nums[j] + nums[k];
				int newDiff = abs(tmp - target);
				if (newDiff == 0) return target;
				if (newDiff < diff)
				{
					diff = newDiff;
					ret = tmp;
				}
				if (tmp < target)
				{
					++j;
				}
				else
				{
					--k;
				}
			}
		}
		return ret;
	}
};
