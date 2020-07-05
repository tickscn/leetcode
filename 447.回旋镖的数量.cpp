/*
 * @lc app=leetcode.cn id=447 lang=cpp
 *
 * [447] 回旋镖的数量
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points)
    {
        int res = 0;
        for (int i = 0; i < points.size(); ++i)
        {
            unordered_map<int, int> iDistanceCount;
            for (int j = 0; j < points.size(); ++j)
            {
                if (i == j) continue;
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                ++iDistanceCount[dx * dx + dy * dy];
            }
            for (auto c : iDistanceCount)
            {
                res += c.second * (c.second - 1);
            }
        }
        return res;
    }
};
// @lc code=end
