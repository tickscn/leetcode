/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 */
class Solution
{
public:
	void invertStr(string& str, int i, int j)
	{
		while (i < j)
		{
			char tmp = str[i];
			str[i++] = str[j];
			str[j--] = tmp;
		}
	}
	void nextPermutation(string& str)
	{
		int n = str.length();
		int i = n - 2;
		int j = n - 1;
		while (i >= 0)
		{
			if (str[i] < str[i + 1]) break;
			--i;
		}
		while (i >= 0 && j > i)
		{
			if (str[j] > str[i])
			{
				char tmp = str[i];
				str[i] = str[j];
				str[j] = tmp;
				break;
			}
			--j;
		}
		invertStr(str, i + 1, n - 1);
	}
	string getPermutation(int n, int k)
	{
		string res(n, '1');
		for (int i = 1; i < n; ++i)
		{
			res[i] = '1' + i;
		}
		if (n == 1) return res;
		for (int i = 1; i < k; ++i)
		{
			nextPermutation(res);
		}

		return res;
	}
};
