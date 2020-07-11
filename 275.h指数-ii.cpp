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
        int i;
        const int size = citations.size();
        for (i = 0; i < citations.size(); ++i)
        {
            if (citations[size - 1 - i] < i + 1) break;
        }
        return i;
    }
};
// @lc code=end
