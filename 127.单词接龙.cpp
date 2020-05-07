/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 *
 * https://leetcode-cn.com/problems/word-ladder/description/
 *
 * algorithms
 * Medium (41.25%)
 * Likes:    287
 * Dislikes: 0
 * Total Accepted:    35.6K
 * Total Submissions: 86.2K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * 给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord
 * 的最短转换序列的长度。转换需遵循如下规则：
 *
 *
 * 每次转换只能改变一个字母。
 * 转换过程中的中间单词必须是字典中的单词。
 *
 *
 * 说明:
 *
 *
 * 如果不存在这样的转换序列，返回 0。
 * 所有单词具有相同的长度。
 * 所有单词只由小写字母组成。
 * 字典中不存在重复的单词。
 * 你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
 *
 *
 * 示例 1:
 *
 * 输入:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 *
 * 输出: 5
 *
 * 解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 * ⁠    返回它的长度 5。
 *
 *
 * 示例 2:
 *
 * 输入:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 *
 * 输出: 0
 *
 * 解释: endWord "cog" 不在字典中，所以无法进行转换。
 *
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        if (wordList.size() == 0) return 0;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) return 0;
        unordered_set<string> front;
        unordered_set<string> tail;
        front.insert(beginWord);
        tail.insert(endWord);
        return bfs(front, tail, wordSet, 2);
    }
    int bfs(unordered_set<string>& f, unordered_set<string>& t, unordered_set<string>& wordSet, int res)
    {
        if (f.size() == 0) return 0;
        if (f.size() > t.size()) return bfs(t, f, wordSet, res);
        unordered_set<string> neighbor;
        for (auto s : f) { wordSet.erase(s); }
        for (string s : f)
        {
            for (size_t i = 0; i < s.length(); ++i)
            {
                char temp = s[i];
                for (char ch = 'a'; ch <= 'z'; ++ch)
                {
                    if (temp == ch) continue;
                    s[i] = ch;
                    if (wordSet.count(s) != 0)
                    {
                        if (t.count(s) != 0)
                            return res;
                        else
                            neighbor.insert(s);
                    }
                }
                s[i] = temp;
            }
        }
        return bfs(neighbor, t, wordSet, res + 1);
    }
};
// @lc code=end
