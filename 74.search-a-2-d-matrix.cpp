/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */
class Solution
{
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target)
	{
		int m = matrix.size();
		if (m == 0) return false;
		int n = matrix[0].size();
		if (n == 0) return false;
		int low = 0, high = m - 1;
		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (matrix[mid][0] == target)
				return true;
			else if (matrix[mid][0] > target)
				high = mid - 1;
			else
				low = mid + 1;
		}
		int row = high;
		if (row < 0) return false;
		low  = 0;
		high = n - 1;
		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (matrix[row][mid] == target)
				return true;
			else if (matrix[row][mid] > target)
				high = mid - 1;
			else
				low = mid + 1;
		}
		return false;
	}
};
