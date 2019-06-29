/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */
class Solution
{
public:
	void rotate(vector<vector<int>>& matrix)
	{
		int size = matrix.size();
		if (size < 2) return;
		for (int i = 0; i < size / 2; ++i)
		{
			for (int j = i; j < size - 1 - i; ++j)
			{
				int tmp = matrix[i][j];
				matrix[i][j] = matrix[size - 1 - j][i];
				matrix[size - 1 - j][i] = matrix[size - 1 - i][size - 1 - j];
				matrix[size - 1 - i][size - 1 - j] = matrix[j][size - 1 - i];
				matrix[j][size - 1 - i] = tmp;
			}
		}
	}
};
