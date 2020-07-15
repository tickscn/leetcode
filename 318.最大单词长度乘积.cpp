/*
 * @lc app=leetcode.cn id=318 lang=cpp
 *
 * [318] 最大单词长度乘积
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<string>& words)
    {
        int size = words.size();
        vector<int> hash(size, 0);
        for (int i = 0; i < size; ++i)
            for (char c : words[i]) hash[i] |= 1 << (c - 'a');
        int res = 0;
        for (int i = 0; i < size; ++i)
            for (int j = i + 1; j < size; ++j)
                if ((hash[i] & hash[j]) == 0) res = max(res, static_cast<int>(words[i].length() * words[j].length()));
        return res;
    }
};
// @lc code=end
