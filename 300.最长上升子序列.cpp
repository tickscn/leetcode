/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        vector<int> dp(nums.size());
        int res = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            int left = 0, right = res;
            while (left < right)
            {
                int mid = left + (right - left) / 2;
                if (dp[mid] < nums[i])
                    left = mid + 1;
                else
                    right = mid;
            }
            dp[left] = nums[i];
            if (left == res) ++res;
        }
        return res;
    }
};
// @lc code=end
