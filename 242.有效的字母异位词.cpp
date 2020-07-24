/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t)
    {
        int Map[26]{0};
        for (char c : s)
        {
            ++Map[c - 'a'];
        }
        for (char c : t)
        {
            --Map[c - 'a'];
        }
        for (int i = 0; i < 26; ++i)
        {
            if (Map[i] != 0) return false;
        }
        return true;
    }
};
// @lc code=end
