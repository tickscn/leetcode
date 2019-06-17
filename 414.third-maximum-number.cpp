/*
 * @lc app=leetcode id=414 lang=cpp
 *
 * [414] Third Maximum Number
 */
#include <climits>
class Solution
{
public:
	int thirdMax(vector<int>& nums)
	{
		long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;
		for (int n : nums)
		{
			if (n > first)
			{
				third = second;
				second = first;
				first = n;
			}
			else if (n > second && n < first)
			{
				third = second;
				second = n;
			}
			else if (n > third && n < second)
			{
				third = n;
			}
		}
		return third == LONG_MIN ? first : third;
	}
};
