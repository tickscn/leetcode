/*
 * @lc app=leetcode id=88 lang=c
 *
 * [88] Merge Sorted Array
 */

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	int i = m + n - 1;
	--m;
	--n;
	while (m >= 0 && n >= 0)
	{
		if (nums1[m] > nums2[n])
		{
			nums1[i] = nums1[m];
			--m;
		}
		else
		{
			nums1[i] = nums2[n];
			--n;
		}
		--i;
	}
	while (n >= 0)
	{
		nums1[i] = nums2[n];
		--i;
		--n;
	}
}
