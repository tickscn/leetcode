/*
 * @lc app=leetcode.cn id=275 lang=cpp
 *
 * [275] H指数 II
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations)
    {
        if (citations.empty()) return 0;
        const int size = citations.size();
        int left = 1 - size, right = 0;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (citations[size + mid - 1] < 1 - mid)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -right;
    }
};
// @lc code=end
