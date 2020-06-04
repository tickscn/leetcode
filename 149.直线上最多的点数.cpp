/*
 * @lc app=leetcode.cn id=149 lang=cpp
 *
 * [149] 直线上最多的点数
 *
 * https://leetcode-cn.com/problems/max-points-on-a-line/description/
 *
 * algorithms
 * Hard (22.27%)
 * Likes:    144
 * Dislikes: 0
 * Total Accepted:    12.3K
 * Total Submissions: 55.1K
 * Testcase Example:  '[[1,1],[2,2],[3,3]]'
 *
 * 给定一个二维平面，平面上有 n 个点，求最多有多少个点在同一条直线上。
 *
 * 示例 1:
 *
 * 输入: [[1,1],[2,2],[3,3]]
 * 输出: 3
 * 解释:
 * ^
 * |
 * |        o
 * |     o
 * |  o  
 * +------------->
 * 0  1  2  3  4
 *
 *
 * 示例 2:
 *
 * 输入: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
 * 输出: 4
 * 解释:
 * ^
 * |
 * |  o
 * |     o        o
 * |        o
 * |  o        o
 * +------------------->
 * 0  1  2  3  4  5  6
 *
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxPoints(vector<vector<int>>& p)
    {
        if (p.size() < 3) return p.size();
        int maxNumber = 0;
        for (int i = 0; i < p.size(); ++i)
        {
            int same = 1;
            for (int j = i + 1; j < p.size(); ++j)
            {
                int curNumber = 0;
                if (p[j] == p[i])
                    ++same;
                else
                {
                    ++curNumber;
                    for (int k = j + 1; k < p.size(); ++k)
                    {
                        if ((long long)((p[k][0]) - p[i][0]) * (p[j][1] - p[i][1])
                            == (long long)(p[j][0] - p[i][0]) * (p[k][1] - p[i][1]))
                            ++curNumber;
                    }
                }
                maxNumber = max(maxNumber, curNumber + same);
            }
        }
        return maxNumber;
    }
};
// @lc code=end
