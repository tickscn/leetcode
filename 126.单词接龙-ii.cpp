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
public:
    bool canTrans(string& from, string& to)
    {
        int count = 0;
        for (size_t i = 0; i < from.size(); ++i)
        {
            if (from[i] == to[i]) ++count;
        }
        return count == from.size() - 1;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
    {
        if (wordList.size() == 0) return {};
        int endIndex, beginIndex;
        size_t size = wordList.size();
        for (endIndex = 0; endIndex < size; ++endIndex)
        {
            if (wordList[endIndex] == endWord) break;
        }
        if (endIndex == size) return {};
        for (beginIndex = 0; beginIndex < size; ++beginIndex)
        {
            if (wordList[beginIndex] == beginWord) break;
        }
        if (beginIndex == size) wordList.push_back(beginWord);
        vector<vector<string>> res;
        vector<string> path;
        queue<int> Q;
        vector<int> depth(size + 1, INT_MAX);    // 路径权重
        vector<vector<int>> neighbor(size + 1);  // 邻接表法构建图
        depth[beginIndex] = 0;
        Q.push(beginIndex);
        while (!Q.empty())
        {
            int temp = Q.front();
            Q.pop();
            for (int i = 0; i < size; ++i)
            {
                if (depth[i] > depth[temp] && canTrans(wordList[temp], wordList[i]))
                {
                    neighbor[temp].push_back(i);
                    if (depth[i] == INT_MAX) Q.push(i);
                    depth[i] = depth[temp] + 1;
                }
            }
        }
        dfs(wordList, beginIndex, endIndex, path, neighbor, res);
        return res;
    }
    void dfs(vector<string>& wordList, int curr, int endIndex, vector<string> path, vector<vector<int>>& neighbor,
             vector<vector<string>>& res)
    {
        path.push_back(wordList[curr]);
        if (endIndex == curr)
        {
            //到达了迭代终点
            res.push_back(path);
            return;
        }
        for (int wordIndex : neighbor[curr])
        {
            //对于邻接节点
            dfs(wordList, wordIndex, endIndex, path, neighbor, res);
        }
    }
};
// @lc code=end
