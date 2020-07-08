/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
    {
        if (t < 0) return false;
        unordered_map<long long, long long> bucket;
        for (int i = 0; i < nums.size(); ++i)
        {
            long long idx = nums[i] / (t + 1LL);
            if (nums[i] < 0) --idx;
            if (bucket.find(idx) != bucket.end())
                return true;
            else if (bucket.find(idx - 1) != bucket.end() && abs(nums[i] - bucket[idx - 1]) <= t)
                return true;
            else if (bucket.find(idx + 1) != bucket.end() && abs(nums[i] - bucket[idx + 1]) <= t)
                return true;
            bucket[idx] = nums[i];
            if (i >= k)
            {
                bucket.erase(nums[i - k] / (t + 1LL));
            }
        }
        return false;
    }
};
// @lc code=end
