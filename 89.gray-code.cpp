/*
 * @lc app=leetcode id=89 lang=cpp
 *
 * [89] Gray Code
 */
class Solution
{
public:
	vector<int> grayCode(int n)
	{
		vector<int> res(1 << n);
		for (int i = 0; i < 1 << n; ++i) res[i] = i ^ (i / 2);
		return res;
	}
};
