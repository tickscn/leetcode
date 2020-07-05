/*
 * @lc app=leetcode.cn id=453 lang=cpp
 *
 * [453] 最小移动次数使数组元素相等
 */

// @lc code=start
class Solution {
public:
    int minMoves(vector<int>& nums)
    {
        int res = 0, Min = INT_MAX;
        for (int num : nums)
        {
            Min = num < Min ? num : Min;
        }
        for (int num : nums)
        {
            res += num - Min;
        }
        return res;
    }
};
// @lc code=end
