/*
 * @lc app=leetcode.cn id=214 lang=cpp
 *
 * [214] 最短回文串
 *
 * https://leetcode-cn.com/problems/shortest-palindrome/description/
 *
 * algorithms
 * Hard (31.53%)
 * Likes:    147
 * Dislikes: 0
 * Total Accepted:    8.8K
 * Total Submissions: 27.8K
 * Testcase Example:  '"aacecaaa"'
 *
 * 给定一个字符串 s，你可以通过在字符串前面添加字符将其转换为回文串。找到并返回可以用这种方式转换的最短回文串。
 *
 * 示例 1:
 *
 * 输入: "aacecaaa"
 * 输出: "aaacecaaa"
 *
 *
 * 示例 2:
 *
 * 输入: "abcd"
 * 输出: "dcbabcd"
 *
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string shortestPalindrome(string s)
    {
        int length = s.length();
        if (length < 2) return s;
        vector<vector<bool>> dp(length, vector<bool>(length, false));
        int maxL = 1;
        for (int i = 0; i < length; ++i) dp[i][0] = true;
        for (int l = 1; l < length; ++l)
        {
            for (int i = 0; i < length - l; ++i)
                if (l == 1)
                {
                    if (s[i] == s[i + l])
                    {
                        dp[i][1] = true;
                        if (i == 0) maxL = maxL > 2 ? maxL : 2;
                    }
                }
                else
                {
                    if (s[i] == s[i + l] && dp[i + 1][l - 2])
                    {
                        dp[i][l] = true;
                        if (i == 0) maxL = max(maxL, l + 1);
                    }
                }
        }
        string tmp = s.substr(maxL);
        return string(tmp.rbegin(), tmp.rend()) + s;
    }
};
// @lc code=end
