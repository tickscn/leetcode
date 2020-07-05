/*
 * @lc app=leetcode.cn id=443 lang=cpp
 *
 * [443] 压缩字符串
 */

// @lc code=start
class Solution {
public:
    int compress(vector<char>& chars)
    {
        int l = 1, count = 1;
        char temp = chars[0];
        for (int i = 1; i < chars.size(); ++i)
        {
            if (chars[i] == temp)
            {
                ++count;
                continue;
            }
            temp = chars[i];
            if (count != 1)
            {
                if (count < 10)
                    chars[l++] = '0' + count;
                else
                {
                    string t = to_string(count);
                    for (char c : t)
                    {
                        chars[l++] = c;
                    }
                }
            }
            chars[l++] = temp;
            count      = 1;
        }
        if (count != 1)
        {
            if (count < 10)
                chars[l++] = '0' + count;
            else
            {
                string t = to_string(count);
                for (char c : t)
                {
                    chars[l++] = c;
                }
            }
        }
        return l;
    }
};
// @lc code=end
