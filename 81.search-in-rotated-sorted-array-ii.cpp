/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 */
class Solution
{
public:
	bool search(vector<int>& nums, int target)
	{
		int size = nums.size();
		if (size == 0) return false;
		int roateNum;
		int i = 0;
		while (i < size - 1)
		{
			if (nums[i + 1] < nums[i]) break;
			++i;
		}
		roateNum = i + 1;
		int left = 0, right = size - 1;
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (nums[(mid + size + roateNum) % size] == target)
				return true;
			else if (nums[(mid + size + roateNum) % size] > target)
				right = mid - 1;
			else
				left = mid + 1;
		}
		return false;
	}
};
