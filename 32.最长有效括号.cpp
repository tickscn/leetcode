/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 *
 * https://leetcode-cn.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (30.28%)
 * Likes:    625
 * Dislikes: 0
 * Total Accepted:    55.2K
 * Total Submissions: 181.8K
 * Testcase Example:  '"(()"'
 *
 * 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
 *
 * 示例 1:
 *
 * 输入: "(()"
 * 输出: 2
 * 解释: 最长有效括号子串为 "()"
 *
 *
 * 示例 2:
 *
 * 输入: ")()())"
 * 输出: 4
 * 解释: 最长有效括号子串为 "()()"
 *
 *
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s)
    {
        int length = s.length();
        if (length < 2) return 0;
        int* dp        = (int*)calloc(length, sizeof(int));
        int max_length = 0;
        for (int i = 1; i < length; ++i)
        {
            if (s[i] == ')')
            {
                if (s[i - 1] == '(')
                    dp[i] = i > 1 ? dp[i - 2] + 2 : 2;
                else if (i - 1 - dp[i - 1] >= 0 && s[i - 1 - dp[i - 1]] == '(')
                    dp[i] = dp[i - 1] + 2 + (i - 1 - dp[i - 1] > 1 ? dp[i - 2 - dp[i - 1]] : 0);
            }
            max_length = max_length > dp[i] ? max_length : dp[i];
        }
        return max_length;
    }
};
// @lc code=end
