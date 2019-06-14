/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */
#include <set>
using namespace std;

class Solution
{
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
	{
		set<int> num1(nums1.begin(), nums1.end()), res;
		for (int a : nums2)
		{
			if (num1.count(a))
			{
				res.insert(a);
			}
		}
		return vector<int>(res.begin(), res.end());
	}
};
