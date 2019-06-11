/*
 * @lc app=leetcode id=278 lang=c
 *
 * [278] First Bad Version
 */
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n)
{
	int low = 1, hight = n;
	int mid;
	while (1)
	{
		mid = low + (hight - low) / 2;
		if (isBadVersion(mid))
		{
			if (mid == 1 || !isBadVersion(mid - 1))
				return mid;
			hight = mid;
		}
		else
		{
			low = mid + 1;
		}
	}
}
