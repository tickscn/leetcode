/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */
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
		int size     = 9;
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

	bool sudokuSolver(vector<vector<char>>& board, int i, int j)
	{
		if (i > 8)
		{
			return true;
		}
		if (board[i][j] == '.')
		{
			for (char ch = '1'; ch <= '9'; ++ch)
			{
				board[i][j] = ch;
				if (isValidSudoku(board))
				{
					if (sudokuSolver(board, (j + 1) / 9 + i, (j + 1) % 9))
					{
						return true;
					}
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
