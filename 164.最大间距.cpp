/*
 * @lc app=leetcode.cn id=164 lang=cpp
 *
 * [164] 最大间距
 *
 * https://leetcode-cn.com/problems/maximum-gap/description/
 *
 * algorithms
 * Hard (55.04%)
 * Likes:    150
 * Dislikes: 0
 * Total Accepted:    14.9K
 * Total Submissions: 27K
 * Testcase Example:  '[3,6,9,1]'
 *
 * 给定一个无序的数组，找出数组在排序之后，相邻元素之间最大的差值。
 *
 * 如果数组元素个数小于 2，则返回 0。
 *
 * 示例 1:
 *
 * 输入: [3,6,9,1]
 * 输出: 3
 * 解释: 排序后的数组是 [1,3,6,9], 其中相邻元素 (3,6) 和 (6,9) 之间都存在最大差值 3。
 *
 * 示例 2:
 *
 * 输入: [10]
 * 输出: 0
 * 解释: 数组元素个数小于 2，因此返回 0。
 *
 * 说明:
 *
 *
 * 你可以假设数组中所有元素都是非负整数，且数值在 32 位有符号整数范围内。
 * 请尝试在线性时间复杂度和空间复杂度的条件下解决此问题。
 *
 *
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumGap(vector<int>& nums)
    {
        if (nums.size() < 2) return 0;
        vector<pair<int, int>> bucket(nums.size() + 1, make_pair(-1, INT_MAX));
        int numMax = 0, numMin = INT_MAX;
        for (int num : nums)
        {
            numMax = max(numMax, num);
            numMin = min(numMin, num);
        }
        if (numMax == numMin) return 0;
        int averageSize = (numMax - numMin) / bucket.size() + 1;
        for (int num : nums)
        {
            int index            = (num - numMin) / averageSize;
            bucket[index].first  = max(num, bucket[index].first);
            bucket[index].second = min(num, bucket[index].second);
        }
        int res = 0;
        int pre = 0;
        for (int i = 1; i < bucket.size(); ++i)
            if (bucket[i].first > 0)
            {
                res = max(res, bucket[i].second - bucket[pre].first);
                pre = i;
            }
        return res;
    }
};
// @lc code=end
