/*
 * @lc app=leetcode id=53 lang=c
 *
 * [53] Maximum Subarray
 */

int findCroMaxSubArr(int* ar, int n)
{
	int mid = n / 2;
	int left_sum, right_sum, sum = 0;
	left_sum = ar[mid];
	right_sum = 0;
	for (int i = mid; i >= 0; --i)
	{
		sum += ar[i];
		if (sum > left_sum)
		{
			left_sum = sum;
		}
	}
	sum = 0;
	for (int i = mid + 1; i < n; ++i)
	{
		sum += ar[i];
		if (sum > right_sum)
		{
			right_sum = sum;
		}
	}
	return left_sum + right_sum;
}

int maxSubArray(int* nums, int numsSize)
{
	int ret, right, mid;
	if (numsSize == 1)
		return nums[0];
	else
	{
		mid = numsSize / 2;
		ret = maxSubArray(nums, mid);
		right = maxSubArray(nums + mid, numsSize - mid);
		mid = findCroMaxSubArr(nums, numsSize);
		if (right > ret)
			ret = right;
		if (mid > ret)
			ret = mid;
		return ret;
	}
}
