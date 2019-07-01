/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */
class Solution
{
public:
	bool canJump(vector<int>& nums)
	{
		int size = nums.size();
		int max = 0;
		for (int i = 0; i < size; ++i)
		{
			if (i > max) return false;
			max = i + nums[i] > max ? i + nums[i] : max;
		}
		return true;
	}
};
