/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */
#include <vector>
using namespace std;
class Solution
{
public:
	vector<vector<int>> threeSum(vector<int>& nums)
	{
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		int size = nums.size();
		for (int i = 0; i < size - 2; ++i)
		{
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			int j = i + 1, k = size - 1;
			int tmp = -nums[i];
			while (j < k)
			{
				if (nums[j] + nums[k] == tmp)
				{
					res.push_back({-tmp, nums[j], nums[k]});
					do
					{
						++j;
					} while (nums[j] == nums[j - 1] && j < size - 1);
					do
					{
						--k;
					} while (nums[k] == nums[k + 1] && k > 0);
				}
				else if (2 * nums[k] < tmp)
				{
					break;
				}
				else if (2 * nums[j] > tmp)
				{
					break;
				}
				else if (nums[j] + nums[k] < tmp)
				{
					do
					{
						++j;
					} while (nums[j] == nums[j - 1] && j < size - 1);
				}
				else
				{
					do
					{
						--k;
					} while (nums[k] == nums[k + 1] && k > 0);
				}
			}
		}
		return res;
	}
};
