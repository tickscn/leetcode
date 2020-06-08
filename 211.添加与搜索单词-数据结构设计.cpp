/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 *
 * https://leetcode-cn.com/problems/add-and-search-word-data-structure-design/description/
 *
 * algorithms
 * Medium (44.84%)
 * Likes:    125
 * Dislikes: 0
 * Total Accepted:    11.5K
 * Total Submissions: 25.7K
 * Testcase Example:  '["WordDictionary","addWord","addWord","addWord","search","search","search","search"]\n' +
  '[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]'
 *
 * 设计一个支持以下两种操作的数据结构：
 *
 * void addWord(word)
 * bool search(word)
 *
 *
 * search(word) 可以搜索文字或正则表达式字符串，字符串只包含字母 . 或 a-z 。 . 可以表示任何一个字母。
 *
 * 示例:
 *
 * addWord("bad")
 * addWord("dad")
 * addWord("mad")
 * search("pad") -> false
 * search("bad") -> true
 * search(".ad") -> true
 * search("b..") -> true
 *
 *
 * 说明:
 *
 * 你可以假设所有单词都是由小写字母 a-z 组成的。
 *
 */

// @lc code=start
class WordDictionary {
public:
    char c;
    bool isTail;
    WordDictionary* child[26];

    /** Initialize your data structure here. */
    WordDictionary(char _c = '0') : c(_c), isTail(false)
    {
        memset(child, 0, sizeof(child));
    }

    /** Adds a word into the data structure. */
    void addWord(string word)
    {
        WordDictionary* pt = this;
        for (char ch : word)
        {
            if (!pt->child[ch - 'a']) pt->child[ch - 'a'] = new WordDictionary(ch);
            pt = pt->child[ch - 'a'];
        }
        pt->isTail = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one
     * letter. */
    bool search(string word)
    {
        WordDictionary* pt = this;
        for (size_t i = 0; i < word.length(); ++i)
        {
            if (word[i] != '.')
            {
                if (!pt->child[word[i] - 'a']) return false;
                pt = pt->child[word[i] - 'a'];
            }
            else
            {
                for (int j = 0; j < 26; ++j)
                {
                    if (pt->child[j] && pt->child[j]->search(word.substr(i + 1))) { return true; }
                }
                return false;
            }
        }
        return pt->isTail;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end
