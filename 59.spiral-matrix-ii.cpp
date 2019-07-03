/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */
class Solution
{
public:
	vector<vector<int>> generateMatrix(int n)
	{
		if (n == 0) return {};
		int l = 0, u = 1, d = n, r = n;
		int size = r * d;
		vector<vector<int>> res(n, vector<int>(n));
		--r;
		--d;
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
			res[rows][cols] = i + 1;
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
