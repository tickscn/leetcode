/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */
class Solution
{
public:
	int largestRectangleArea(vector<int>& heights)
	{
		int size = heights.size();
		if (size == 0) return 0;
		if (size == 1) return heights[0];
		int max = heights[0];
		stack<int> St;
		for (int i = 0; i < size; ++i)
		{
			if (St.empty() || heights[i] >= heights[St.top()])
			{
				St.push(i);
			}
			else
			{
				int top = St.top();
				St.pop();
				int width = St.empty() ? i : i - 1 - St.top();
				max       = heights[top] * width > max ? heights[top] * width : max;
				--i;
			}
		}
		while (!St.empty())
		{
			int top = St.top();
			St.pop();
			int width = St.empty() ? size : size - 1 - St.top();
			max       = heights[top] * width > max ? heights[top] * width : max;
		}
		return max;
	}
};
