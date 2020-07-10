/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums)
    {
        vector<int> res(2, 0);
        int tmp = 0;
        for (int num : nums)
        {
            tmp ^= num;
        }
        int b = 1;
        while ((tmp & 1) == 0)
        {
            tmp >>= 1;
            b <<= 1;
        }
        for (int num : nums)
        {
            if (num & b)
                res[0] ^= num;
            else
                res[1] ^= num;
        }
        return res;
    }
};
// @lc code=end
