/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
unordered_map<char, int> priority{{')', 0}, {'+', 1}, {'-', 1}, {'(', 2}};
class Solution {
public:
    int calculate(string s)
    {
        stack<char> op;
        stack<int> nums;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == ' ') continue;
            if (priority.count(s[i]))
            {
                while (!op.empty() && priority[s[i]] <= priority[op.top()])
                {
                    char Op = op.top();
                    op.pop();
                    if (Op != ')')
                    {
                        int res = Eval(Op, nums);
                        nums.push(res);
                    }
                    else
                        break;
                }
                if (s[i] == '(')
                    op.push(')');
                else if (s[i] != ')')
                    op.push(s[i]);
                continue;
            }
            int j = i;
            while (i < s.length() && isdigit(s[i])) ++i;
            nums.push(atoi(s.substr(j, i - j).c_str()));
            --i;
        }
        while (!op.empty())
        {
            char Op = op.top();
            op.pop();
            if (Op != ')')
            {
                int res = Eval(Op, nums);
                nums.push(res);
            }
        }
        return nums.top();
    }
    int Eval(char op, stack<int>& nums)
    {
        int num2 = nums.top();
        nums.pop();
        int num1 = nums.top();
        nums.pop();
        if (op == '+')
            return num1 + num2;
        else
            return num1 - num2;
    }
};
// @lc code=end
