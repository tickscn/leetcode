/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
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
	int maximalRectangle(vector<vector<char>>& matrix)
	{
		int rows = matrix.size();
		if (rows == 0) return 0;
		int cols = matrix[0].size();
		if (cols == 0) return 0;
		int res = 0;
		vector<int> heights(cols, 0);
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				heights[j] = matrix[i][j] == '0' ? 0 : heights[j] + 1;
			}
			res = max(res, largestRectangleArea(heights));
		}
		return res;
	}
};
