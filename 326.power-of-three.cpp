/*
 * @lc app=leetcode id=326 lang=cpp
 *
 * [326] Power of Three
 */
class Solution
{
public:
	bool isPowerOfThree(int n)
	{
		if (n < 1) return false;
		while (n % 3 == 0)
		{
			n /= 3;
		}
		return n == 1;
	}
};
