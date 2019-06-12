/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 */
#include <vector>
using std::vector;
class NumArray
{
private:
	vector<int> dq;

public:
	NumArray(vector<int>& nums)
	    : dq(nums.size() + 1, 0)
	{
		for (int i = 1; i <= nums.size(); i++)
		{
			dq[i] = dq[i - 1] + nums[i - 1];
		}
	}

	int sumRange(int i, int j)
	{
		return dq[j + 1] - dq[i];
	}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
