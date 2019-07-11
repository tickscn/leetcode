/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */
class Solution
{
public:
	int removeDuplicates(vector<int>& nums)
	{
		int size = nums.size();
		if (size < 3) return size;
		int res = 1;
		for (int i = 2; i < size; ++i)
		{
			if (nums[i] != nums[res] || nums[i] != nums[res - 1])
			{
				nums[++res] = nums[i];
			}
		}
		return res + 1;
	}
};
