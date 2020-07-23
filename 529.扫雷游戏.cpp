/*
 * @lc app=leetcode.cn id=529 lang=cpp
 *
 * [529] 扫雷游戏
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    int rows;
    int cols;

public:
    void dfs(vector<vector<char>>& board, int x, int y)
    {
        if (x < 0 || x >= rows || y < 0 || y >= cols || board[x][y] != 'E')
            return;
        else
        {
            char count = '0';
            for (int i = -1; i <= 1; ++i)
                for (int j = -1; j <= 1; ++j)
                {
                    if (x + i < 0 || x + i >= rows || y + j < 0 || y + j >= cols) continue;
                    if (board[x + i][y + j] == 'M') ++count;
                }
            if (count == '0')
            {
                board[x][y] = 'B';
                for (int i = -1; i <= 1; ++i)
                    for (int j = -1; j <= 1; ++j)
                    {
                        dfs(board, x + i, y + j);
                    }
            }
            else
                board[x][y] = count;
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& c)
    {
        if (board[c[0]][c[1]] == 'M')
        {
            board[c[0]][c[1]] = 'X';
            return board;
        }
        rows = board.size();
        cols = board[0].size();
        dfs(board, c[0], c[1]);
        return board;
    }
};
// @lc code=end
