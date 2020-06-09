/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 *
 * https://leetcode-cn.com/problems/wiggle-subsequence/description/
 *
 * algorithms
 * Medium (41.65%)
 * Likes:    182
 * Dislikes: 0
 * Total Accepted:    18.7K
 * Total Submissions: 44.8K
 * Testcase Example:  '[1,7,4,9,2,5]'
 *
 * 如果连续数字之间的差严格地在正数和负数之间交替，则数字序列称为摆动序列。第一个差（如果存在的话）可能是正数或负数。少于两个元素的序列也是摆动序列。
 *
 * 例如， [1,7,4,9,2,5] 是一个摆动序列，因为差值 (6,-3,5,-7,3) 是正负交替出现的。相反, [1,4,7,2,5] 和
 * [1,7,4,5,5] 不是摆动序列，第一个序列是因为它的前两个差值都是正数，第二个序列是因为它的最后一个差值为零。
 *
 * 给定一个整数序列，返回作为摆动序列的最长子序列的长度。
 * 通过从原始序列中删除一些（也可以不删除）元素来获得子序列，剩下的元素保持其原始顺序。
 *
 * 示例 1:
 *
 * 输入: [1,7,4,9,2,5]
 * 输出: 6
 * 解释: 整个序列均为摆动序列。
 *
 *
 * 示例 2:
 *
 * 输入: [1,17,5,10,13,15,10,5,16,8]
 * 输出: 7
 * 解释: 这个序列包含几个长度为 7 摆动序列，其中一个可为[1,17,10,13,10,16,8]。
 *
 * 示例 3:
 *
 * 输入: [1,2,3,4,5,6,7,8,9]
 * 输出: 2
 *
 * 进阶:
 * 你能否用 O(n) 时间复杂度完成此题?
 *
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums)
    {
        size_t size = nums.size();
        if (size < 2) return size;
        vector<pair<int, int>> dp(size);
        // first 最后一次是下降
        // second 最后一次是上升
        dp[0].first = dp[0].second = 1;
        for (size_t i = 1; i < size; ++i)
        {
            if (nums[i] > nums[i - 1])
            {
                dp[i].first  = dp[i - 1].first;  // 不是降
                dp[i].second = dp[i - 1].first + 1;
            }
            else if (nums[i] < nums[i - 1])
            {
                dp[i].first  = dp[i - 1].second + 1;
                dp[i].second = dp[i - 1].second;
            }
            else
            {
                dp[i].first  = dp[i - 1].first;
                dp[i].second = dp[i - 1].second;
            }
        }
        return max(dp[size - 1].first, dp[size - 1].second);
    }
};
// @lc code=end
