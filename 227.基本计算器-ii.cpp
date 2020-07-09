/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    static unordered_map<char, char> priority;

public:
    int Operate(char op, int num1, int num2)
    {
        switch (op)
        {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': return num1 / num2;
        default: return 0;
        }
    }
    int calculate(string s)
    {
        stack<char> op;
        stack<int> number;
        size_t i = 0;
        while (i != s.length())
        {
            while (s[i] == ' ') ++i;
            if (i == s.length()) break;
            if (priority.find(s[i]) != priority.end())
            {
                while (!op.empty() && priority[s[i]] <= priority[op.top()])
                {
                    int num2 = number.top();
                    number.pop();
                    int num1 = number.top();
                    number.pop();
                    char Op = op.top();
                    op.pop();
                    number.push(Operate(Op, num1, num2));
                }
                op.push(s[i++]);
            }
            else
            {
                int j = i;
                while (isdigit(s[i])) ++i;
                number.push(stoi(s.substr(j, i - j + 1)));
            }
        }
        while (!op.empty())
        {
            int num2 = number.top();
            number.pop();
            int num1 = number.top();
            number.pop();
            char Op = op.top();
            op.pop();
            number.push(Operate(Op, num1, num2));
        }
        return number.top();
    }
};
unordered_map<char, char> Solution::priority{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
// @lc code=end
