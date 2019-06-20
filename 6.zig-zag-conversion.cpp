/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 */
#include <string>
using namespace std;
class Solution
{
public:
	string convert(string s, int numRows)
	{
		int length = s.length();
		if (length == 0 || numRows == 0 || numRows == 1) return s;
		string result;
		int lenRows = 2 * numRows - 2;
		for (int i = 0; i < numRows; i++)
			for (int j = i; j < length; j += lenRows)
			{
				result += s[j];
				if (i != 0 && i != numRows - 1 && j - 2 * i + lenRows < length) result += s[j - 2 * i + lenRows];
			}
		return result;
	}
};
