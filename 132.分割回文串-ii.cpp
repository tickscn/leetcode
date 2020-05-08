/*
 * @lc app=leetcode.cn id=132 lang=cpp
 *
 * [132] 分割回文串 II
 *
 * https://leetcode-cn.com/problems/palindrome-partitioning-ii/description/
 *
 * algorithms
 * Hard (42.80%)
 * Likes:    139
 * Dislikes: 0
 * Total Accepted:    10.5K
 * Total Submissions: 24.5K
 * Testcase Example:  '"aab"'
 *
 * 给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
 *
 * 返回符合要求的最少分割次数。
 *
 * 示例:
 *
 * 输入: "aab"
 * 输出: 1
 * 解释: 进行一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。
 *
 *
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int minCut(string s)
    {
        if (s.empty() || s.length() == 1) return 0;
        int length = s.length();
        vector<vector<bool>> isPartition(length, vector<bool>(length, false));
        vector<int> dp(length, 0);
        for (int i = 0; i < length; ++i)
        {
            dp[i] = i;
            for (int j = 0; j <= i; ++j)
            {
                if (s[i] == s[j] && (i - j < 2 || isPartition[j + 1][i - 1]))
                {
                    isPartition[j][i] = true;

                    dp[i] = j == 0 ? 0 : min(dp[i], dp[j - 1] + 1);
                }
            }
        }
        return dp[length - 1];
    }
};
// @lc code=end
