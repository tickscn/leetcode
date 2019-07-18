/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
	void recursion(vector<string>& res, string& str, string& s, int n = 0, int index = 0)
	{
		if (n == 4)
		{
			if (index == s.length()) res.push_back(str);
			return;
		}
		for (int k = 1; k < 4; ++k)
		{
			if (s.length() < k + index) break;
			int val = 0;
			for (int i = 0; i < k; ++i)
			{
				val = val * 10 + s[index + i] - '0';
			}
			if (val > 255 || (val == 0 && k != 1) || (val != 0 && val < pow(10, k - 1))) continue;
			for (int i = 0; i < k; ++i) str.push_back(s[index + i]);
			if (n < 3) str.push_back('.');
			recursion(res, str, s, n + 1, index + k);
			if (n < 3) str.pop_back();
			for (int i = 0; i < k; ++i) str.pop_back();
		}
	}
	vector<string> restoreIpAddresses(string s)
	{
		if (s.length() < 4) return {};
		vector<string> res;
		string str;
		recursion(res, str, s);
		return res;
	}
};
