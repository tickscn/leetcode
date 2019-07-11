/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */
class Solution
{
public:
	bool matchWord(vector<vector<char>>& board, string& word, int i, int j, int cnt)
	{
		if (cnt == word.length()) return true;
		bool res = false;
		if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
		{
			return res;
		}
		if (board[i][j] != word[cnt]) return res;
		board[i][j] = '#';

		res = res || matchWord(board, word, i + 1, j, cnt + 1);
		res = res || matchWord(board, word, i - 1, j, cnt + 1);
		res = res || matchWord(board, word, i, j + 1, cnt + 1);
		res = res || matchWord(board, word, i, j - 1, cnt + 1);

		board[i][j] = word[cnt];
		return res;
	}
	bool exist(vector<vector<char>>& board, string word)
	{
		for (int i = 0; i < board.size(); ++i)
			for (int j = 0; j < board[0].size(); ++j)
			{
				if (matchWord(board, word, i, j, 0)) return true;
			}
		return false;
	}
};
