/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 *
 * https://leetcode-cn.com/problems/summary-ranges/description/
 *
 * algorithms
 * Medium (52.54%)
 * Likes:    49
 * Dislikes: 0
 * Total Accepted:    10.2K
 * Total Submissions: 19.4K
 * Testcase Example:  '[0,1,2,4,5,7]'
 *
 * 给定一个无重复元素的有序整数数组，返回数组区间范围的汇总。
 *
 * 示例 1:
 *
 * 输入: [0,1,2,4,5,7]
 * 输出: ["0->2","4->5","7"]
 * 解释: 0,1,2 可组成一个连续的区间; 4,5 可组成一个连续的区间。
 *
 * 示例 2:
 *
 * 输入: [0,2,3,4,6,8,9]
 * 输出: ["0","2->4","6","8->9"]
 * 解释: 2,3,4 可组成一个连续的区间; 8,9 可组成一个连续的区间。
 *
 */

// @lc code=start
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums)
    {
        if (nums.empty()) return {};
        vector<string> res;
        int beg = 0, end = 0;
        while (end < nums.size())
        {
            while (end + 1 < nums.size() && nums[end + 1] == nums[end] + 1) ++end;
            if (end == beg)
                res.push_back(to_string(nums[beg]));
            else
                res.push_back(to_string(nums[beg]) + "->" + to_string(nums[end]));
            ++end;
            beg = end;
        }
        return res;
    }
};
// @lc code=end
