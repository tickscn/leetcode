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
        unordered_set<int> Set;
        for (int num : nums)
        {
            if (Set.count(num))
                Set.erase(num);
            else
                Set.insert(num);
        }
        return vector<int>(Set.begin(), Set.end());
    }
};
// @lc code=end
