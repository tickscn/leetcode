/*
 * @lc app=leetcode.cn id=1160 lang=cpp
 *
 * [1160] 拼写单词
 */

// @lc code=start
class Solution {
public:
    int countCharacters(vector<string>& words, string chars)
    {
        int res = 0;
        int arMap[26]{0};
        for (char ch : chars) ++arMap[ch - 'a'];
        for (string& word : words)
        {
            int temp[26];
            copy(begin(arMap), end(arMap), begin(temp));
            bool flag = true;
            for (char ch : word)
            {
                if (temp[ch - 'a']-- == 0)
                {
                    flag = false;
                    break;
                }
            }
            if (flag) res += word.length();
        }
        return res;
    }
};
// @lc code=end
