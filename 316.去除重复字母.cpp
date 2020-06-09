/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 *
 * https://leetcode-cn.com/problems/remove-duplicate-letters/description/
 *
 * algorithms
 * Hard (38.82%)
 * Likes:    158
 * Dislikes: 0
 * Total Accepted:    13.4K
 * Total Submissions: 34.3K
 * Testcase Example:  '"bcabc"'
 *
 *
 * 给你一个仅包含小写字母的字符串，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证返回结果的字典序最小（要求不能打乱其他字符的相对位置）。
 *
 *
 *
 * 示例 1:
 *
 * 输入: "bcabc"
 * 输出: "abc"
 *
 *
 * 示例 2:
 *
 * 输入: "cbacdcbc"
 * 输出: "acdb"
 *
 *
 *
 * 注意：该题与 1081
 * https://leetcode-cn.com/problems/smallest-subsequence-of-distinct-characters
 * 相同
 *
 */

// @lc code=start
class Solution {
public:
    string removeDuplicateLetters(string s)
    {
        bool flag[26]{false};
        int count[26]{0};
        for (char ch : s) ++count[ch - 'a'];
        deque<char> dQ;
        for (char ch : s)
        {
            --count[ch - 'a'];
            if (flag[ch - 'a']) continue;
            while (!dQ.empty() && ch < dQ.back() && count[dQ.back() - 'a'])
            {
                flag[dQ.back() - 'a'] = false;
                dQ.pop_back();
            }
            dQ.push_back(ch);
            flag[ch - 'a'] = true;
        }
        return string(dQ.begin(), dQ.end());
    }
};
// @lc code=end
