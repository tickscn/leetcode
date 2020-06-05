/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 *
 * https://leetcode-cn.com/problems/reverse-words-in-a-string/description/
 *
 * algorithms
 * Medium (42.34%)
 * Likes:    175
 * Dislikes: 0
 * Total Accepted:    71.7K
 * Total Submissions: 169.3K
 * Testcase Example:  '"the sky is blue"'
 *
 * 给定一个字符串，逐个翻转字符串中的每个单词。
 *
 *
 *
 * 示例 1：
 *
 * 输入: "the sky is blue"
 * 输出: "blue is sky the"
 *
 *
 * 示例 2：
 *
 * 输入: "  hello world!  "
 * 输出: "world! hello"
 * 解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
 *
 *
 * 示例 3：
 *
 * 输入: "a good   example"
 * 输出: "example good a"
 * 解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 *
 *
 *
 *
 * 说明：
 *
 *
 * 无空格字符构成一个单词。
 * 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
 * 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 *
 *
 *
 *
 * 进阶：
 *
 * 请选用 C 语言的用户尝试使用 O(1) 额外空间复杂度的原地解法。
 *
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void skipWS(string& s, int& i)
    {
        while (i > 0 && s[i - 1] == ' ') --i;
    }
    string reverseWords(string s)
    {
        if (s.empty()) return "";
        string res;
        int i = s.length();
        skipWS(s, i);
        while (i > 0)
        {
            int j = i;
            while (j > 0 && s[j - 1] != ' ') --j;
            res += res.empty() ? s.substr(j, i - j) : " " + s.substr(j, i - j);
            i = j - 1;
            skipWS(s, i);
        }
        return res;
    }
};
// @lc code=end
