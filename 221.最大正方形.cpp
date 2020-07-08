/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
    int rows, cols;

public:
    int maximalSquare(vector<vector<char>>& matrix)
    {
        if ((rows = matrix.size()) == 0) return 0;
        if ((cols = matrix[0].size()) == 0) return 0;
        int res = 0;
        vector<int> pre(cols + 1, 0);
        vector<int> cur(cols + 1, 0);
        for (int i = 0; i < rows; ++i)
        {
            swap(pre, cur);
            fill(cur.begin(), cur.end(), 0);
            for (int j = 0; j < cols; ++j)
            {
                if (matrix[i][j] == '1')
                {
                    cur[j + 1] = 1 + min(cur[j], min(pre[j], pre[j + 1]));
                    res        = max(res, cur[j + 1]);
                }
            }
        }
        return res * res;
    }
};
// @lc code=end
