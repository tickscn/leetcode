/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */

// @lc code=start
#include <vector>
using namespace std;
class NumMatrix {
    int rows, cols;
    vector<vector<int>> dp;

public:
    NumMatrix(vector<vector<int>>& matrix) : rows(matrix.size())
    {
        if (rows == 0) return;
        cols = matrix[0].size();
        dp   = vector<vector<int>>(rows + 1, vector<int>(cols + 1, 0));

        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
            {
                dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j] - dp[i][j] + matrix[i][j];
            }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        if (rows == 0) return 0;
        return dp[row2 + 1][col2 + 1] + dp[row1][col1] - dp[row2 + 1][col1] - dp[row1][col2 + 1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end
