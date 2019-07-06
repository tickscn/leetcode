/*
 * @lc app=leetcode id=65 lang=cpp
 *
 * [65] Valid Number
 */

/*
 * 允许前导 0
 * 允许符号位为 '+'
 * 允许省略整数部分的0
 */
#include <cctype>
#include <string>
using namespace std;
class Solution
{
public:
	inline bool isDigit1to9(char ch)
	{
		return ch >= '1' && ch <= '9';
	}
	inline bool isDigit(char ch)
	{
		return ch >= '0' && ch <= '9';
	}
	inline bool isSign(char ch)
	{
		return ch == '+' || ch == '-';
	}
	bool isNumber(string s)
	{
		int size = s.length();
		int i    = 0;
		if (size == 0) return false;
		bool seenDot   = false;
		bool seenE     = false;
		bool seenNum   = false;
		bool seenDigit = false;
		bool isBegin   = true;
		while (i < size && isblank(s[i])) ++i;
		while (i < size)
		{
			if (isblank(s[i]))
			{
				seenNum = true;
			}
			else if (seenNum)
			{
				return false;
			}
			else if (isSign(s[i]))
			{
				if (!isBegin) return false;
			}
			else if (s[i] == '.')
			{
				if (seenDot || seenE) return false;
				seenDot = true;
				isBegin = false;
			}
			else if (s[i] == 'e')
			{
				if (seenE || !seenDigit) return false;
				seenE     = true;
				seenDigit = false;
				isBegin   = true;
			}
			else if (isDigit(s[i]))
			{
				isBegin   = false;
				seenDigit = true;
			}
			else
			{
				return false;
			}
			++i;
		}
		return seenDigit;
	}
};
