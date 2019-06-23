/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */
class Solution
{
public:
	void invertNums(vector<int>& nums, int i, int j)
	{
		while (i < j)
		{
			int tmp = nums[i];
			nums[i++] = nums[j];
			nums[j--] = tmp;
		}
	}
	void nextPermutation(vector<int>& nums)
	{
		int size = nums.size();
		if (size == 0 || size == 1) return;
		int i = size - 2;
		int j = size - 1;
		while (i >= 0)
		{
			if (nums[i] < nums[i + 1]) break;
			--i;
		}
		while (i >= 0 && j > i)
		{
			if (nums[j] > nums[i])
			{
				int tmp = nums[i];
				nums[i] = nums[j];
				nums[j] = tmp;
				break;
			}
			--j;
		}
		invertNums(nums, i + 1, size - 1);
	}
};
