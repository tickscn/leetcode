/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续1的个数
 */

// @lc code=start
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums)
    {
        int res  = 0;
        int temp = 0;
        for (int num : nums)
        {
            if (num == 1)
            {
                ++temp;
            }
            else
            {
                res  = max(res, temp);
                temp = 0;
            }
        }
        return max(res, temp);
    }
};
// @lc code=end
