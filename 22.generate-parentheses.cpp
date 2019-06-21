/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */
class Solution
{
public:
	void generateParenthesisR(int left, int right, string out, vector<string>& res)
	{
		if (left > right) return;
		if (left == 0 && right == 0)
			res.push_back(out);
		else
		{
			if (left > 0) generateParenthesisR(left - 1, right, out + '(', res);
			if (right > 0) generateParenthesisR(left, right - 1, out + ')', res);
		}
	}
	vector<string> generateParenthesis(int n)
	{
		vector<string> res;
		generateParenthesisR(n, n, "", res);
		return res;
	}
};
