/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int b1 = INT_MAX, b2 = INT_MAX;
        int s1 = 0, s2 = 0;
        for (int price : prices)
        {
            s1 = max(s1, price - b1);
            b1 = min(b1, price);
            s2 = max(s2, price - b2);
            b2 = min(b2, price - s1);
        }
        return s2;
    }
};
// @lc code=end
