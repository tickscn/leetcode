/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */
class Solution
{
public:
	int search(vector<int>& nums, int target)
	{
		int size = nums.size();
		if (size == 0) return -1;
		int index;
		int i = 0;
		while (i < size - 1)
		{
			if (nums[i + 1] < nums[i]) break;
			++i;
		}
		index    = i + 1;
		int left = 0, right = size - 1;
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (nums[(mid + size + index) % size] == target)
				return (mid + size + index) % size;
			else if (nums[(mid + size + index) % size] > target)
				right = mid - 1;
			else
				left = mid + 1;
		}
		return -1;
	}
};
