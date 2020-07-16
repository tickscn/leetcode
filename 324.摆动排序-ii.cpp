/*
 * @lc app=leetcode.cn id=324 lang=cpp
 *
 * [324] 摆动排序 II
 */

// @lc code=start
class Solution {
public:
    int idxTranslation(int i, int n)
    {
        return (2 * i + 1) % (n | 1);
    }

    void wiggleSort(vector<int>& nums)
    {
        int size = nums.size();
        nth_element(nums.begin(), nums.begin() + size / 2, nums.end());
        int mid = nums[size / 2];
        int i = 0, j = 0, k = size;
        while (j < k)
        {
            if (nums[idxTranslation(j, size)] > mid)
            {
                swap(nums[idxTranslation(i++, size)], nums[idxTranslation(j++, size)]);
            }
            else if (nums[idxTranslation(j, size)] < mid)
            {
                swap(nums[idxTranslation(j, size)], nums[idxTranslation(--k, size)]);
            }
            else
                ++j;
        }
    }
};
// @lc code=end
