/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 *
 * https://leetcode-cn.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (67.16%)
 * Likes:    303
 * Dislikes: 0
 * Total Accepted:    38.9K
 * Total Submissions: 57.9K
 * Testcase Example:  '["Trie","insert","search","search","startsWith","insert","search"]\n' +
  '[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * 实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。
 *
 * 示例:
 *
 * Trie trie = new Trie();
 *
 * trie.insert("apple");
 * trie.search("apple");   // 返回 true
 * trie.search("app");     // 返回 false
 * trie.startsWith("app"); // 返回 true
 * trie.insert("app");
 * trie.search("app");     // 返回 true
 *
 * 说明:
 *
 *
 * 你可以假设所有的输入都是由小写字母 a-z 构成的。
 * 保证所有输入均为非空字符串。
 *
 *
 */

// @lc code=start
using namespace std;
class Trie {
    Trie* child[26]{nullptr};
    bool isTail = false;

public:
    /** Initialize your data structure here. */
    Trie() {}

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Trie* pt = this;
        for (char c : word)
        {
            if (!pt->child[c - 'a']) pt->child[c - 'a'] = new Trie();
            pt = pt->child[c - 'a'];
        }
        pt->isTail = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Trie* pt = this;
        for (char c : word)
        {
            if (!pt->child[c - 'a']) return false;
            pt = pt->child[c - 'a'];
        }
        return pt->isTail;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        Trie* pt = this;
        for (char c : prefix)
        {
            if (!pt->child[c - 'a']) return false;
            pt = pt->child[c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
