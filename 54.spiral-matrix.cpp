/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */
#include <vector>
using namespace std;
class Solution
{
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix)
	{
		int l = 0, u = 1, d = matrix.size();
		if (d == 0) return vector<int>(0);
		int r = matrix[0].size();
		int size = r * d;
		--r;
		--d;
		vector<int> res(size);
		if (size == 0) return res;
		res.reserve(size);
		enum
		{
			right,
			down,
			left,
			up
		} dict = right;
		int rows = 0, cols = 0;
		for (int i = 0; i < size; ++i)
		{
			res[i] = matrix[rows][cols];
			switch (dict)
			{
			case right:
				if (cols < r)
				{
					++cols;
					break;
				}
				else
				{
					--r;
					dict = down;
				}
			case down:
				if (rows < d)
				{
					++rows;
					break;
				}
				else
				{
					--d;
					dict = left;
				}
			case left:
				if (cols > l)
				{
					--cols;
					break;
				}
				else
				{
					++l;
					dict = up;
				}

			case up:
				if (rows > u)
				{
					--rows;
					break;
				}
				else
				{
					++u;
					dict = right;
				}
			default:
				if (cols < r)
				{
					++cols;
					break;
				}
				else
				{
					--r;
					dict = down;
				}
			}
		}
		return res;
	}
};
