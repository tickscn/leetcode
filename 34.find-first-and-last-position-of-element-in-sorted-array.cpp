/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */
class Solution
{
public:
	vector<int> searchRange(vector<int>& nums, int target)
	{
		vector<int> res(2, -1);
		int size = nums.size();
		if (size == 0) return res;
		int left = 0, right = size - 1;
		while (right > left)
		{
			int mid = (left + right) / 2;
			if (nums[mid] < target)
				left = mid + 1;
			else
				right = mid;
		}
		if (nums[left] == target)
			res[0] = left;
		else
			return res;
		left = 0;
		right = size - 1;
		while (left < right)
		{
			int mid = (left + right + 1) / 2;
			if (nums[mid] > target)
				right = mid - 1;
			else
				left = mid;
		}
		res[1] = right;
		return res;
	}
};
