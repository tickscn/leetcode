/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */
#include <string>
#include <vector>

using namespace std;
class Solution
{
public:
	string simplifyPath(string path)
	{
		int length = path.length();
		if (length < 2) return "/";
		string res;
		vector<string> stack;
		for (int i = 1, j, k; i < length; i = k + 1)
		{
			string tmp;
			for (j = i; j < length && path[j] == '/'; ++j)
				;
			if (j == length) break;
			for (k = j + 1; k < length && path[k] != '/'; ++k)
				;
			tmp = path.substr(j, k - j);
			if (tmp == "..")
			{
				if (!stack.empty()) stack.pop_back();
			}
			else if (tmp != ".")
				stack.push_back(tmp);
		}
		if (stack.empty()) return "/";
		for (int i = 0; i < stack.size(); ++i)
		{
			res += "/" + stack[i];
		}

		return res;
	}
};
