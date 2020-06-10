/*
 * @lc app=leetcode.cn id=402 lang=cpp
 *
 * [402] 移掉K位数字
 *
 * https://leetcode-cn.com/problems/remove-k-digits/description/
 *
 * algorithms
 * Medium (29.01%)
 * Likes:    227
 * Dislikes: 0
 * Total Accepted:    18.6K
 * Total Submissions: 63.9K
 * Testcase Example:  '"1432219"\n3'
 *
 * 给定一个以字符串表示的非负整数 num，移除这个数中的 k 位数字，使得剩下的数字最小。
 *
 * 注意:
 *
 *
 * num 的长度小于 10002 且 ≥ k。
 * num 不会包含任何前导零。
 *
 *
 * 示例 1 :
 *
 *
 * 输入: num = "1432219", k = 3
 * 输出: "1219"
 * 解释: 移除掉三个数字 4, 3, 和 2 形成一个新的最小的数字 1219。
 *
 *
 * 示例 2 :
 *
 *
 * 输入: num = "10200", k = 1
 * 输出: "200"
 * 解释: 移掉首位的 1 剩下的数字为 200. 注意输出不能有任何前导零。
 *
 *
 * 示例 3 :
 *
 *
 * 输入: num = "10", k = 2
 * 输出: "0"
 * 解释: 从原数字移除所有的数字，剩余为空就是0。
 *
 *
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    string removeKdigits(string num, int k)
    {
        if (k == num.length()) return "0";
        string res = num.substr(0, 1);
        for (int i = 1; i < num.length(); ++i)
        {
            char now = num[i];
            while (!res.empty() && k && now < res.back())
            {
                --k;
                res.pop_back();
            }
            if (now != '0' || !res.empty()) res += now;
        }
        while (k)
        {
            --k;
            res.pop_back();
        }
        return res.empty() ? "0" : res;
    }
};
// @lc code=end
