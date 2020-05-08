/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 *
 * https://leetcode-cn.com/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (39.97%)
 * Likes:    206
 * Dislikes: 0
 * Total Accepted:    33.4K
 * Total Submissions: 83.6K
 * Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * 给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。
 *
 * 找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
 *
 * 示例:
 *
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 *
 *
 * 运行你的函数后，矩阵变为：
 *
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 *
 *
 * 解释:
 *
 * 被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O'
 * 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
 *
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
    size_t rows;
    size_t cols;

public:
    void solve(vector<vector<char>>& board)
    {
        if (board.empty()) return;
        rows = board.size();
        cols = board[0].size();
        for (size_t i = 0; i < rows; ++i)
        {
            dfs(board, i, 0);
            dfs(board, i, cols - 1);
        }
        for (size_t j = 1; j < cols - 1; ++j)
        {
            dfs(board, 0, j);
            dfs(board, rows - 1, j);
        }
        for (size_t i = 0; i < rows; ++i)
            for (size_t j = 0; j < cols; ++j)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '.')
                    board[i][j] = 'O';
            }
    }
    void dfs(vector<vector<char>>& b, int i, int j)
    {
        if (i < 0 || j < 0 || i >= rows || j >= cols || b[i][j] != 'O') return;
        b[i][j] = '.';
        dfs(b, i - 1, j);
        dfs(b, i + 1, j);
        dfs(b, i, j - 1);
        dfs(b, i, j + 1);
    }
};
// @lc code=end
