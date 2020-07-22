/*
 * @lc app=leetcode.cn id=756 lang=cpp
 *
 * [756] 金字塔转换矩阵
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_map<string, set<char>> Map;
    bool pyramidTransition(string bottom, vector<string>& allowed)
    {
        if (bottom.length() < 2) return true;
        for (auto& s : allowed)
        {
            Map[s.substr(0, 2)].insert(s[2]);
        }
        return pyramidTransition(bottom, "");
    }
    bool pyramidTransition(string& bottom, string next)
    {
        if (bottom.length() < 2) return true;
        if (bottom.length() - next.length() == 1) return pyramidTransition(next, "");
        int index = next.length();
        auto S    = Map.find(bottom.substr(index, 2));
        if (S == Map.end()) return false;
        for (auto c : S->second)
        {
            if (pyramidTransition(bottom, next + c)) return true;
        }
        return false;
    }
};
// @lc code=end
