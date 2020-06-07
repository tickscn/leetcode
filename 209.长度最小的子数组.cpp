/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 *
 * https://leetcode-cn.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (42.51%)
 * Likes:    282
 * Dislikes: 0
 * Total Accepted:    45.4K
 * Total Submissions: 106.6K
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * 给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s
 * 的长度最小的连续子数组，并返回其长度。如果不存在符合条件的连续子数组，返回 0。
 *
 * 示例: 
 *
 * 输入: s = 7, nums = [2,3,1,2,4,3]
 * 输出: 2
 * 解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。
 *
 *
 * 进阶:
 *
 * 如果你已经完成了O(n) 时间复杂度的解法, 请尝试 O(n log n) 时间复杂度的解法。
 *
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums)
    {
        int left = 0, right = 0, sum = 0, len = INT_MAX;
        bool flag = false;
        while (right < nums.size())
        {
            sum += nums[right];
            while (sum >= s)
            {
                flag = true;
                len  = min(len, right - left + 1);
                sum -= nums[left];
                ++left;
            }
            ++right;
        }
        return flag ? len : 0;
    }
};
// @lc code=end
