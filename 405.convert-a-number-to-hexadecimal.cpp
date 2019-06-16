/*
 * @lc app=leetcode id=405 lang=cpp
 *
 * [405] Convert a Number to Hexadecimal
 */
class Solution
{
public:
	string toHex(int num)
	{
		string HEX{"0123456789abcdef"};
		if (num == 0) return "0";
		string res;
		int count = 9;
		while (num && --count)
		{
			res = HEX[num & 0xf] + res;
			num >>= 4;
		}
		return res;
	}
};
