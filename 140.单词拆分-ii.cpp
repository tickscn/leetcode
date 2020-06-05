/*
 * @lc app=leetcode.cn id=140 lang=cpp
 *
 * [140] 单词拆分 II
 *
 * https://leetcode-cn.com/problems/word-break-ii/description/
 *
 * algorithms
 * Hard (37.90%)
 * Likes:    169
 * Dislikes: 0
 * Total Accepted:    16K
 * Total Submissions: 42.2K
 * Testcase Example:  '"catsanddog"\n["cat","cats","and","sand","dog"]'
 *
 * 给定一个非空字符串 s 和一个包含非空单词列表的字典
 * wordDict，在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的句子。
 *
 * 说明：
 *
 *
 * 分隔时可以重复使用字典中的单词。
 * 你可以假设字典中没有重复的单词。
 *
 *
 * 示例 1：
 *
 * 输入:
 * s = "catsanddog"
 * wordDict = ["cat", "cats", "and", "sand", "dog"]
 * 输出:
 * [
 * "cats and dog",
 * "cat sand dog"
 * ]
 *
 *
 * 示例 2：
 *
 * 输入:
 * s = "pineapplepenapple"
 * wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
 * 输出:
 * [
 * "pine apple pen apple",
 * "pineapple pen apple",
 * "pine applepen apple"
 * ]
 * 解释: 注意你可以重复使用字典中的单词。
 *
 *
 * 示例 3：
 *
 * 输入:
 * s = "catsandog"
 * wordDict = ["cats", "dog", "sand", "and", "cat"]
 * 输出:
 * []
 *
 *
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    size_t maxL = 0;

public:
    void helper(vector<string>& res, string& s, unordered_set<string>& dict, string str, size_t b)
    {
        if (b == s.length())
        {
            res.emplace_back(std::move(str));
            return;
        }
        for (size_t j = 1; j <= maxL && b + j <= s.length(); ++j)
        {
            if (dict.find(s.substr(b, j)) != dict.end())
            { helper(res, s, dict, (b == 0 ? s.substr(0, j) : str + " " + s.substr(b, j)), b + j); }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict)
    {
        vector<string> res;
        if (s.empty() || wordDict.empty()) return res;
        unordered_set<string> dict(make_move_iterator(wordDict.begin()), make_move_iterator(wordDict.end()));
        for (auto& a : dict) { maxL = max(maxL, a.length()); }
        bool dp[s.length() + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = true;
        for (int i = 1; i <= s.length(); ++i)
            for (int j = (i > maxL ? i - maxL : 0); j < i; ++j)
            {
                if (dp[j] && dict.count(s.substr(j, i - j)))
                {
                    dp[i] = true;
                    break;
                }
            }
        if (!dp[s.length()]) return res;
        string str;
        helper(res, s, dict, str, 0);
        return res;
    }
};
// @lc code=end
