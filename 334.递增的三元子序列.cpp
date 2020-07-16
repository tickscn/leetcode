/*
 * @lc app=leetcode.cn id=334 lang=cpp
 *
 * [334] 递增的三元子序列
 */

// @lc code=start
class Solution {
public:
    bool increasingTriplet(vector<int>& nums)
    {
        if (nums.size() < 3) return false;
        int a = INT_MAX, b = INT_MAX;
        for (int num : nums)
        {
            if (num <= a)
                a = num;
            else if (num <= b)
                b = num;
            else
                return true;
        }
        return false;
    }
};
// @lc code=end
