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
        int i;
        sort(citations.begin(), citations.end(), std::greater<int>());
        for (i = 0; i < citations.size(); ++i)
        {
            if (citations[i] < i + 1) break;
        }
        return i;
    }
};
// @lc code=end
