/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k)
	{
		unordered_map<int, int> myhash;
		for (int i = 0; i < nums.size(); i++)
		{
			if (myhash.find(nums[i]) != myhash.end())
			{
				if (i - myhash[nums[i]] <= k)
					return true;
				myhash[nums[i]] = i;
			}
			else
			{
				myhash[nums[i]] = i;
			}
		}

		return false;
	}
};
