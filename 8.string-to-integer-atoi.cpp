/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */
class Solution
{
public:
	int myAtoi(string str)
	{
		int ret = 0;
		bool working = false;
		bool negative = false;
		for (char ch : str)
		{
			if (ch >= '0' && ch <= '9')
			{
				working = true;
				if (!negative && (ret > 214748364 || (ret == 214748364 && ch > '6'))) return INT_MAX;
				if (negative && (ret > 214748364 || (ret == 214748364 && ch > '7'))) return INT_MIN;
				ret = ret * 10 + (ch - '0');
			}
			else if (ch == ' ' && !working)
			{
				continue;
			}
			else if (ch == '-' && !working)
			{
				negative = true;
				working = true;
			}
			else if (ch == '+' && !working)
			{
				working = true;
			}
			else
				break;
		}
		return negative ? -ret : ret;
	}
};
