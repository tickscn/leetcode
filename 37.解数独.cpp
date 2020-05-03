/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 *
 * https://leetcode-cn.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (61.19%)
 * Likes:    401
 * Dislikes: 0
 * Total Accepted:    26.6K
 * Total Submissions: 43.5K
 * Testcase Example:
 * '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * 编写一个程序，通过已填充的空格来解决数独问题。
 *
 * 一个数独的解法需遵循如下规则：
 *
 *
 * 数字 1-9 在每一行只能出现一次。
 * 数字 1-9 在每一列只能出现一次。
 * 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
 *
 *
 * 空白格用 '.' 表示。
 *
 *
 *
 * 一个数独。
 *
 *
 *
 * 答案被标成红色。
 *
 * Note:
 *
 *
 * 给定的数独序列只包含数字 1-9 和字符 '.' 。
 * 你可以假设给定的数独只有唯一解。
 * 给定数独永远是 9x9 形式的。
 *
 *
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool hasRepetition(vector<vector<char>>& board, int x, int y, char* map)
    {
        for (int i = x; i < x + 3; ++i)
        {
            for (int j = y; j < y + 3; ++j)
            {
                if (board[i][j] == '.') continue;
                if (map[board[i][j] - '0'] == 1) { return true; }
                ++map[board[i][j] - '0'];
            }
        }
        memset(map, 0, 10);
        return false;
    }
    bool isValidSudoku(vector<vector<char>>& board)
    {
        char map[10] = {0};
        int size     = 9;
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                if (board[i][j] == '.') continue;
                if (map[board[i][j] - '0'] == 1) { return false; }
                ++map[board[i][j] - '0'];
            }
            memset(map, 0, 10);
        }
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                if (board[j][i] == '.') continue;
                if (map[board[j][i] - '0'] == 1) { return false; }
                ++map[board[j][i] - '0'];
            }
            memset(map, 0, 10);
        }
        for (int i = 0; i < size; i += 3)
        {
            for (int j = 0; j < size; j += 3)
            {
                if (hasRepetition(board, i, j, map)) { return false; }
            }
        }
        return true;
    }

    bool sudokuSolver(vector<vector<char>>& board, int i, int j)
    {
        if (i > 8) { return true; }
        if (board[i][j] == '.')
        {
            for (char ch = '1'; ch <= '9'; ++ch)
            {
                board[i][j] = ch;
                if (isValidSudoku(board))
                {
                    if (sudokuSolver(board, (j + 1) / 9 + i, (j + 1) % 9)) { return true; }
                }
            }
            board[i][j] = '.';
        }
        else if (sudokuSolver(board, i + (j + 1) / 9, (j + 1) % 9))
        {
            return true;
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board)
    {
        sudokuSolver(board, 0, 0);
    }
};
// @lc code=end
