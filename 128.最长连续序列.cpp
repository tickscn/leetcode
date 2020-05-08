/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 *
 * https://leetcode-cn.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Hard (48.61%)
 * Likes:    317
 * Dislikes: 0
 * Total Accepted:    37.8K
 * Total Submissions: 77.5K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * 给定一个未排序的整数数组，找出最长连续序列的长度。
 *
 * 要求算法的时间复杂度为 O(n)。
 *
 * 示例:
 *
 * 输入: [100, 4, 200, 1, 3, 2]
 * 输出: 4
 * 解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。
 *
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        unordered_set<int> hashSet(nums.begin(), nums.end());
        int longest = 0;
        for (auto num : nums)
        {
            if (hashSet.count(num - 1)) continue;
            int len = 1;
            while (hashSet.count(num + 1))
            {
                ++num;
                ++len;
            }
            longest = max(longest, len);
        }
        return longest;
    }
};
// @lc code=end
