/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */
#include <cstring>
class Solution
{
public:
	bool hasRepetition(vector<vector<char>>& board, int x, int y, char* map)
	{
		for (int i = x; i < x + 3; ++i)
		{
			for (int j = y; j < y + 3; ++j)
			{
				if (board[i][j] == '.') continue;
				if (map[board[i][j] - '0'] == 1)
				{
					return true;
				}
				++map[board[i][j] - '0'];
			}
		}
		memset(map, 0, 10);
		return false;
	}
	bool isValidSudoku(vector<vector<char>>& board)
	{
		char map[10] = {0};
		int size = 9;
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				if (board[i][j] == '.') continue;
				if (map[board[i][j] - '0'] == 1)
				{
					return false;
				}
				++map[board[i][j] - '0'];
			}
			memset(map, 0, 10);
		}
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				if (board[j][i] == '.') continue;
				if (map[board[j][i] - '0'] == 1)
				{
					return false;
				}
				++map[board[j][i] - '0'];
			}
			memset(map, 0, 10);
		}
		for (int i = 0; i < size; i += 3)
		{
			for (int j = 0; j < size; j += 3)
			{
				if (hasRepetition(board, i, j, map))
				{
					return false;
				}
			}
		}
		return true;
	}
};
