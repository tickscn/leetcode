/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */
#include <unordered_map>
#include <vector>
using namespace std;
class Pair
{
public:
	int a;
	int b;
	Pair(int x, int y)
	    : a(x)
	    , b(y)
	{
	}
};
class Solution
{
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target)
	{
		vector<vector<int>> res;
		unordered_map<int, vector<Pair>> map;
		int size = nums.size();
		sort(nums.begin(), nums.end());
		for (int i = 0; i < size - 1; ++i)
		{
			for (int j = i + 1; j < size; ++j)
			{
				map[nums[i] + nums[j]].push_back({i, j});
			}
		}
		for (int i = 0; i < size - 3; ++i)
		{
			if (i != 0 && nums[i] == nums[i - 1]) continue;
			for (int j = i + 1; j < size - 2; ++j)
			{
				if (j != i + 1 && nums[j] == nums[j - 1]) continue;
				if (map.find(target - nums[i] - nums[j]) != map.end())
				{
					vector<Pair>& tmp = map[target - nums[i] - nums[j]];
					bool isFirst = true;
					for (int k = 0; k < tmp.size(); k++)
					{
						if (tmp[k].a <= j) continue;
						if (isFirst || res.back()[2] != nums[tmp[k].a])
						{
							res.push_back(vector<int>{nums[i], nums[j], nums[tmp[k].a], nums[tmp[k].b]});
							isFirst = false;
						}
					}
				}
			}
		}
		return res;
	}
};
