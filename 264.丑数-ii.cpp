/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int nthUglyNumber(int n)
    {
        unique_ptr<int[]> dp(new int[n]);
        int idx[3] = {0, 0, 0};
        dp[0]      = 1;
        for (int i = 1; i < n; ++i)
        {
            int n1 = dp[idx[0]] * 2;
            int n2 = dp[idx[1]] * 3;
            int n3 = dp[idx[2]] * 5;
            dp[i]  = min(n1, min(n2, n3));
            if (dp[i] == n1) ++idx[0];
            if (dp[i] == n2) ++idx[1];
            if (dp[i] == n3) ++idx[2];
        }
        return dp[n - 1];
    }
};
// @lc code=end
