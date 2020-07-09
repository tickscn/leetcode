/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
private:
    int rows;
    int cols;

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        if ((rows = matrix.size()) == 0 || (cols = matrix[0].size()) == 0) return false;
        int i = 0, j = cols - 1;
        while (i < rows && j >= 0)
        {
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] < target)
                ++i;
            else
                --j;
        }
        return false;
    }
};
// @lc code=end
