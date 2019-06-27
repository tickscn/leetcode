/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */
class Solution
{
public:
	int trap(vector<int>& height)
	{
		int size = height.size();
		int res = 0;
		if (size < 3) return res;
		int maxIndex = 0;
		for (int i = 1; i < size; ++i)
		{
			if (height[i] > height[maxIndex]) maxIndex = i;
		}
		for (int i = 0, lheight = 0; i < maxIndex; ++i)
		{
			if (height[i] > lheight)
			{
				lheight = height[i];
			}
			else
			{
				res += lheight - height[i];
			}
		}
		for (int i = size - 1, rheight = 0; i > maxIndex; i--)
		{
			if (height[i] > rheight)
			{
				rheight = height[i];
			}
			else
			{
				res += rheight - height[i];
			}
		}

		return res;
	}
};
