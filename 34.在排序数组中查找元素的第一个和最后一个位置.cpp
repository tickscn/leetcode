/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 *
 * https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (39.41%)
 * Likes:    411
 * Dislikes: 0
 * Total Accepted:    86.7K
 * Total Submissions: 219.9K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
 *
 * 你的算法时间复杂度必须是 O(log n) 级别。
 *
 * 如果数组中不存在目标值，返回 [-1, -1]。
 *
 * 示例 1:
 *
 * 输入: nums = [5,7,7,8,8,10], target = 8
 * 输出: [3,4]
 *
 * 示例 2:
 *
 * 输入: nums = [5,7,7,8,8,10], target = 6
 * 输出: [-1,-1]
 *
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        vector<int> res(2, -1);
        if (nums.empty()) return res;
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = (right + left) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }
        if (nums[left] == target)
            res[0] = left;
        else
            return res;
        left  = 0;
        right = nums.size() - 1;
        while (left < right)
        {
            int mid = (left + right + 1) / 2;
            if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid;
        }
        res[1] = right;
        return res;
    }
};
// @lc code=end
