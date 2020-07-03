/*
 * @lc app=leetcode.cn id=495 lang=cpp
 *
 * [495] 提莫攻击
 */

// @lc code=start
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration)
    {
        if (timeSeries.empty()) return 0;
        int res = duration;
        int i   = timeSeries[0];
        for (int i = 1; i < timeSeries.size(); ++i)
        {
            int temp = timeSeries[i] - timeSeries[i - 1];
            res += temp < duration ? temp : duration;
        }
        return res;
    }
};
// @lc code=end
