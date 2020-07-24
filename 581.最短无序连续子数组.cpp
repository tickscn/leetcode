/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 */

// @lc code=start

static int i, j, Max, Min;
class Solution {

public:
    int findUnsortedSubarray(vector<int>& nums)
    {
        i = 0;
        j = nums.size() - 1;
        while (i < j && nums[i] <= nums[i + 1]) ++i;
        if (i == j) return 0;
        while (j > i && nums[j] >= nums[j - 1]) --j;
        Max = nums[i];
        Min = nums[i];
        for (int k = i + 1; k <= j; ++k)
        {
            Max = max(nums[k], Max);
            Min = min(nums[k], Min);
        }
        while (i > 0 && nums[i - 1] > Min) --i;
        while (j < nums.size() - 1 && nums[j + 1] < Max) ++j;
        return j - i + 1;
    }
};
// @lc code=end
