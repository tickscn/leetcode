/*
 * @lc app=leetcode id=367 lang=cpp
 *
 * [367] Valid Perfect Square
 */
class Solution
{
public:
	bool isPerfectSquare(int num)
	{
		/*  连续奇数的和
		 *	for (int i = 1; num > 0; i += 2)
		 *	{
		 *		num -= i;
		 *	}
		 *	return num == 0;
		 */

		/* 二分查找
		 *        int low = 1, high = num;
		 *        long mid;
		 *        while (low <= high)
		 *        {
		 *            mid = low + (high - low) / 2;
		 *            long tmp = mid * mid;
		 *            if (tmp == num)
		 *                return true;
		 *            else if (tmp > num)
		 *                high = mid - 1;
		 *            else
		 *                low = mid + 1;
		 *        }
		 *        return false;
		 */
		/* 牛顿迭代法 */
		long i = num / 2 + 1;
		while (i * i > num) i = (i + num / i) / 2;
		return i * i == num;
	}
};
