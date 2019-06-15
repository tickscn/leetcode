/*
 * @lc app=leetcode id=374 lang=cpp
 *
 * [374] Guess Number Higher or Lower
 */
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution
{
public:
	int guessNumber(int n)
	{
		int low = 1, high = n;
		int ret;
		while (low <= high)
		{
			ret = low + (high - low) / 2;
			if (guess(ret) == 0)
				return ret;
			else if (guess(ret) == -1)
				high = ret;
			else
				low = ret + 1;
		}
		return ret;
	}
};
