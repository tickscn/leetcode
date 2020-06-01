/*
 * @lc app=leetcode.cn id=126 lang=cpp
 *
 * [126] 单词接龙 II
 *
 * https://leetcode-cn.com/problems/word-ladder-ii/description/
 *
 * algorithms
 * Hard (31.55%)
 * Likes:    156
 * Dislikes: 0
 * Total Accepted:    9.1K
 * Total Submissions: 29.1K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * 给定两个单词（beginWord 和 endWord）和一个字典 wordList，找出所有从 beginWord 到 endWord
 * 的最短转换序列。转换需遵循如下规则：
 *
 *
 * 每次转换只能改变一个字母。
 * 转换过程中的中间单词必须是字典中的单词。
 *
 *
 * 说明:
 *
 *
 * 如果不存在这样的转换序列，返回一个空列表。
 * 所有单词具有相同的长度。
 * 所有单词只由小写字母组成。
 * 字典中不存在重复的单词。
 * 你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
 *
 *
 * 示例 1:
 *
 * 输入:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 *
 * 输出:
 * [
 * ⁠ ["hit","hot","dot","dog","cog"],
 * ["hit","hot","lot","log","cog"]
 * ]
 *
 *
 * 示例 2:
 *
 * 输入:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 *
 * 输出: []
 *
 * 解释: endWord "cog" 不在字典中，所以不存在符合要求的转换序列。
 *
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
    void dfs(unordered_map<string, unordered_set<string>>& preLevel, const string& end, vector<string> path,
             vector<vector<string>>& res)
    {
        path.emplace_back(end);
        if (preLevel.count(end) == 0)
        {
            res.emplace_back(make_move_iterator(path.rbegin()), make_move_iterator(path.rend()));
            return;
        }
        for (const string& word : preLevel[end]) dfs(preLevel, word, path, res);
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
    {
        unordered_set<string> wSet(wordList.begin(), wordList.end());
        if (wSet.find(endWord) == wSet.end()) return {};
        unordered_map<string, unordered_set<string>> preLevel;
        unordered_set<string> q = {beginWord}, curLevel;
        for (; q.size() && preLevel.count(endWord) == 0; q = curLevel)
        {
            for (const string& word : q) wSet.erase(word);
            curLevel.clear();
            for (const string& word : q)
            {
                for (int i = 0; i < word.length(); ++i)
                {
                    string cur = word;
                    for (char ch = 'a'; ch <= 'z'; ++ch)
                    {
                        if (word[i] == ch) continue;
                        cur[i] = ch;
                        if (wSet.find(cur) != wSet.end())
                        {
                            preLevel[cur].insert(word);
                            curLevel.insert(cur);
                        }
                    }
                }
            }
        }
        if (preLevel.size() == 0) return {};
        vector<vector<string>> result;
        dfs(preLevel, endWord, {}, result);
        return result;
    }
};
// @lc code=end
