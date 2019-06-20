/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */
class Solution
{
public:
	inline int min(int a, int b)
	{
		return a < b ? a : b;
	}
	inline int max(int a, int b)
	{
		return a > b ? a : b;
	}
	int maxArea(vector<int>& height)
	{
		int size = height.size();
		int i = 0, j = size - 1;
		int res = j * min(height[0], height[j]);
		while (i < j)
		{
			height[i] < height[j] ? ++i : --j;
			res = max(res, (j - i) * min(height[i], height[j]));
		}
		return res;
	}
};
