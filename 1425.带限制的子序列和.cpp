/*
 * @lc app=leetcode.cn id=1425 lang=cpp
 *
 * [1425] 带限制的子序列和
 */

// @lc code=start
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k)
    {
        int size = nums.size();
        int res  = INT_MIN;
        vector<int> dp(size, 0);
        deque<int> Q;
        for (int i = 0; i < size; ++i)
        {
            if (!Q.empty() && i - Q.front() > k)
            {
                Q.pop_front();
            }
            dp[i] = max(nums[i], nums[i] + (Q.empty() ? 0 : dp[Q.front()]));
            while (!Q.empty() && dp[Q.back()] < dp[i]) Q.pop_back();
            Q.push_back(i);
            res = max(res, dp[i]);
        }
        return res;
    }
};
// @lc code=end
