/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */
#include <iterator>
#include <vector>
using namespace std;
class Solution
{
public:
	double findKth(vector<int>& nums1, int beg1, int n1, vector<int>& nums2, int beg2, int n2, int k)
	{
		if (n1 > n2) return findKth(nums2, beg2, n2, nums1, beg1, n1, k);
		if (n1 == 0) return nums2[beg2 + k - 1];
		if (k == 1) return nums1[beg1] < nums2[beg2] ? nums1[beg1] : nums2[beg2];
		int k_div_2 = n1 < k / 2 ? n1 : k / 2;
		if (nums1[beg1 + k_div_2 - 1] < nums2[beg2 + k - k_div_2 - 1])
		{
			return findKth(nums1, beg1 + k_div_2, n1 - k_div_2, nums2, beg2, n2, k - k_div_2);
		}
		if (nums1[beg1 + k_div_2 - 1] > nums2[beg2 + k - k_div_2 - 1])
		{
			return findKth(nums1, beg1, n1, nums2, beg2 + k - k_div_2, n2 + k_div_2 - k, k_div_2);
		}
		return nums1[beg1 + k_div_2 - 1];
	}
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
	{
		int m = nums1.size(), n = nums2.size();
		int total = m + n;
		if (total & 0x1)
			return findKth(nums1, 0, m, nums2, 0, n, total / 2 + 1);
		else
			return (findKth(nums1, 0, m, nums2, 0, n, total / 2) + findKth(nums1, 0, m, nums2, 0, n, total / 2 + 1)) / 2.0;
	}
};
