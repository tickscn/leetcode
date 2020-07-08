/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        make_heap(nums.begin(), nums.begin() + k, greater<int>());
        for (int i = k; i < nums.size(); ++i)
        {
            if (nums[i] > nums[0])
            {
                pop_heap(nums.begin(), nums.begin() + k, greater<int>());
                nums[k - 1] = nums[i];
                push_heap(nums.begin(), nums.begin() + k, greater<int>());
            }
        }
        return nums[0];
    }
};
// @lc code=end
