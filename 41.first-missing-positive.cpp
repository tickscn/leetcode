/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */
class Solution
{
public:
	int firstMissingPositive(vector<int>& nums)
	{
		int i;
		int size = nums.size();
		if (size < 1) return 1;
		for (i = 0; i < size; ++i)
		{
			if (nums[i] == i + 1) continue;
			while (nums[i] <= size && nums[i] > 0 && nums[i] != nums[nums[i] - 1])
			{
				int temp = nums[nums[i] - 1];
				nums[nums[i] - 1] = nums[i];
				nums[i] = temp;
			}
		}
		for (i = 0; i < size; ++i)
		{
			if (nums[i] != i + 1) break;
		}
		return i + 1;
	}
};
