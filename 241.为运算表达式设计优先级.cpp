/*
 * @lc app=leetcode.cn id=241 lang=cpp
 *
 * [241] 为运算表达式设计优先级
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    unordered_map<string, vector<int>> table;

public:
    vector<int> diffWaysToCompute(const string& input)
    {
        if (input.empty()) return {};
        if (table.count(input)) return table[input];
        vector<int> res;
        for (int i = 0; i < input.length(); ++i)
        {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*')
            {
                vector<int> r1 = diffWaysToCompute(input.substr(0, i));
                vector<int> r2 = diffWaysToCompute(input.substr(i + 1));
                for (int n1 : r1)
                    for (int n2 : r2)
                    {
                        if (input[i] == '+')
                            res.push_back(n1 + n2);
                        else if (input[i] == '-')
                            res.push_back(n1 - n2);
                        else
                            res.push_back(n1 * n2);
                    }
            }
        }
        if (res.empty()) res.push_back(stoi(input));
        table[input] = res;
        return res;
    }
};
// @lc code=end
