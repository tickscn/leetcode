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
		vector<int> index(size);
		int i = 0;
		while (i < size - 1)
		{
			if (nums[i + 1] < nums[i]) break;
			++i;
		}
		for (int j = 0; j < size; ++j)
		{
			index[j] = (j + size + i + 1) % size;
		}
		int left = 0, right = size - 1;
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (nums[index[mid]] == target)
				return index[mid];
			else if (nums[index[mid]] > target)
				right = mid - 1;
			else
				left = mid + 1;
		}
		return -1;
	}
};
