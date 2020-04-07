/*
 * @lc app=leetcode id=4 lang=java
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (27.36%)
 * Likes:    6311
 * Dislikes: 965
 * Total Accepted:    624.4K
 * Total Submissions: 2.2M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 * 
 * You may assume nums1 and nums2 cannot be both empty.
 * 
 * Example 1:
 * 
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * 
 * 
 * Example 2:
 * 
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 * 
 * 
 */

// @lc code=start
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int length1 = nums1.length;
        int length2 = nums2.length;
        if ((length1 + length2) % 2 == 0)
            return (findKth(nums1, nums2, 0, length1, 0, length2, (length1 + length2) / 2 + 1)
                    + findKth(nums1, nums2, 0, length1, 0, length2, (length1 + length2) / 2)) / 2.0;
        return findKth(nums1, nums2, 0, length1, 0, length2, (length1 + length2) / 2 + 1);

    }

    private int findKth(int[] nums1, int[] nums2, int beg1, int l1, int beg2, int l2, int k) {
        if (l1 > l2)
            return findKth(nums2, nums1, beg2, l2, beg1, l1, k);
        if (l1 == 0)
            return nums2[beg2 + k - 1];
        if (k == 1)
            return Math.min(nums1[beg1], nums2[beg2]);
        int tmp = Math.min(k / 2, l1);
        if (nums1[beg1 + tmp - 1] < nums2[beg2 + k - tmp - 1])
            return findKth(nums1, nums2, beg1 + tmp, l1 - tmp, beg2, l2, k - tmp);
        if (nums1[beg1 + tmp - 1] > nums2[beg2 + k - tmp - 1])
            return findKth(nums1, nums2, beg1, l1, beg2 + k - tmp, l2 - k + tmp, tmp);
        return nums1[beg1 + tmp - 1];
    }
}
// @lc code=end
