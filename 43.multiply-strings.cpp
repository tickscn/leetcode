/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */
#include <string>
using namespace std;
class Solution
{
public:
	string multiply(string num1, string num2)
	{
		int length1 = num1.length();
		int length2 = num2.length();
		if (num1[0] == '0' || num2[0] == '0') return "0";
		vector<char> res(length1 + length2, '0');
		string ret;
		for (int i = length1 - 1; i >= 0; --i)
		{
			for (int j = length2 - 1; j >= 0; --j)
			{
				int mul = (num1[i] - '0') * (num2[j] - '0');
				int sum = mul + res[i + j + 1] - '0';
				res[i + j] += (sum / 10);
				res[i + j + 1] = (sum % 10) + '0';
			}
		}
		int i = 0;
		while (res[i] == '0') ++i;
		while (i < length1 + length2)
		{
			ret.push_back(res[i]);
			++i;
		}
		return ret;
	}
};
