/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H 指数
 */

// @lc code=start
#include <bits/stdc++.h>
using std::vector;
class Solution {
public:
    int hIndex(vector<int>& citations)
    {
        sort(citations.begin(), citations.end(), std::greater<int>());
        int left = 0, right = citations.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (citations[mid] < mid + 1)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }
};
// @lc code=end
