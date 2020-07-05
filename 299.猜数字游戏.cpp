/*
 * @lc app=leetcode.cn id=299 lang=cpp
 *
 * [299] 猜数字游戏
 */

// @lc code=start
class Solution {
public:
    string getHint(string secret, string guess)
    {
        int table[10] = {0};
        int countA = 0, countB = 0;
        for (int i = 0; i < secret.size(); ++i)
        {
            if (secret[i] == guess[i])
                ++countA;
            else
            {
                if (table[guess[i] - '0']-- > 0) ++countB;
                if (table[secret[i] - '0']++ < 0) ++countB;
            }
        }
        return to_string(countA) + "A" + to_string(countB) + "B";
    }
};
// @lc code=end
