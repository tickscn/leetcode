/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 *
 * https://leetcode-cn.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (49.51%)
 * Likes:    587
 * Dislikes: 0
 * Total Accepted:    113.3K
 * Total Submissions: 228.7K
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
 *
 * 岛屿总是被水包围，并且每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。
 *
 * 此外，你可以假设该网格的四条边均被水包围。
 *
 *
 *
 * 示例 1:
 *
 * 输入:
 * 11110
 * 11010
 * 11000
 * 00000
 * 输出: 1
 *
 *
 * 示例 2:
 *
 * 输入:
 * 11000
 * 11000
 * 00100
 * 00011
 * 输出: 3
 * 解释: 每座岛屿只能由水平和/或竖直方向上相邻的陆地连接而成。
 *
 *
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
private:
    int rows, cols;

public:
    void dfs(vector<vector<char>>& grid, int i, int j)
    {
        if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] != '1') return;
        ++grid[i][j];
        dfs(grid, i - 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i + 1, j);
        dfs(grid, i, j + 1);
    }
    int numIslands(vector<vector<char>>& grid)
    {
        if (grid.empty() || grid[0].empty()) return 0;
        rows    = grid.size();
        cols    = grid[0].size();
        int res = 0;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (grid[i][j] == '1')
                {
                    ++res;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }
};
// @lc code=end
