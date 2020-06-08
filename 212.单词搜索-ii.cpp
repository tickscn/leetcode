/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 *
 * https://leetcode-cn.com/problems/word-search-ii/description/
 *
 * algorithms
 * Hard (40.81%)
 * Likes:    172
 * Dislikes: 0
 * Total Accepted:    14.9K
 * Total Submissions: 36.4K
 * Testcase Example:  '[["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]\n' +
  '["oath","pea","eat","rain"]'
 *
 * 给定一个二维网格 board 和一个字典中的单词列表 words，找出所有同时在二维网格和字典中出现的单词。
 *
 *
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。
 *
 * 示例:
 *
 * 输入:
 * words = ["oath","pea","eat","rain"] and board =
 * [
 * ⁠ ['o','a','a','n'],
 * ⁠ ['e','t','a','e'],
 * ⁠ ['i','h','k','r'],
 * ⁠ ['i','f','l','v']
 * ]
 *
 * 输出: ["eat","oath"]
 *
 * 说明:
 * 你可以假设所有输入都由小写字母 a-z 组成。
 *
 * 提示:
 *
 *
 * 你需要优化回溯算法以通过更大数据量的测试。你能否早点停止回溯？
 * 如果当前单词不存在于所有单词的前缀中，则可以立即停止回溯。什么样的数据结构可以有效地执行这样的操作？散列表是否可行？为什么？
 * 前缀树如何？如果你想学习如何实现一个基本的前缀树，请先查看这个问题： 实现Trie（前缀树）。
 *
 *
 */

// @lc code=start
#include <memory>
#include <string>
#include <vector>
using namespace std;
struct TrieNode {
    char c;
    bool isTail;
    shared_ptr<TrieNode> child[26];
    TrieNode(char _c) : c(_c), isTail(false) {}
};
class Trie {
    shared_ptr<TrieNode> root;

public:
    Trie() : root(make_shared<TrieNode>('0')) {}
    void addWord(const string& word)
    {
        auto pt = root;
        for (char ch : word)
        {
            if (!pt->child[ch - 'a']) pt->child[ch - 'a'] = make_shared<TrieNode>(ch);
            pt = pt->child[ch - 'a'];
        }
        pt->isTail = true;
    }
    void remove(const string& word)
    {
        auto pt = root;
        for (char ch : word)
        {
            if (pt->child[ch - 'a'])
                pt = pt->child[ch - 'a'];
            else
                return;
        }
        pt->isTail = false;
    }
    bool search(const string& word) const
    {
        auto pt = root;
        for (char ch : word)
        {
            if (!pt->child[ch - 'a']) return false;
            pt = pt->child[ch - 'a'];
        }
        return pt->isTail;
    }

    bool startWith(const string& prefix) const
    {
        auto pt = root;
        for (char ch : prefix)
        {
            if (!pt->child[ch - 'a']) return false;
            pt = pt->child[ch - 'a'];
        }
        return true;
    }
};
class Solution {
    int rows, cols;

public:
    void helper(vector<string>& res, string str, int i, int j, vector<vector<char>>& board, Trie& t)
    {
        if (i < 0 || j < 0 || i >= rows || j >= cols || board[i][j] == '.' || !t.startWith(str)) return;
        char temp = board[i][j];
        str += temp;
        if (t.search(str))
        {
            t.remove(str);
            res.emplace_back(str);
        }
        board[i][j] = '.';
        helper(res, str, i + 1, j, board, t);
        helper(res, str, i, j + 1, board, t);
        helper(res, str, i - 1, j, board, t);
        helper(res, str, i, j - 1, board, t);
        board[i][j] = temp;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
        Trie t;
        for (auto& word : words) t.addWord(word);
        vector<string> res;
        rows = board.size();
        cols = board[0].size();
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j) helper(res, "", i, j, board, t);
        return res;
    }
};
// @lc code=end
