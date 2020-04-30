/*
 * @lc app=leetcode.cn id=22 lang=java
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (75.31%)
 * Likes:    987
 * Dislikes: 0
 * Total Accepted:    121.1K
 * Total Submissions: 160.8K
 * Testcase Example:  '3'
 *
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：n = 3
 * 输出：[
 * ⁠      "((()))",
 * ⁠      "(()())",
 * ⁠      "(())()",
 * ⁠      "()(())",
 * ⁠      "()()()"
 * ⁠    ]
 * 
 * 
 */

// @lc code=start
class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<>();
        backtrace(res, "", n, n);
        return res;
    }

    public static void backtrace(List<String> res, String tmp, int l, int r) {
        if (l > r)
            return;
        if (l == 0 && r == 0)
            res.add(tmp);
        else {
            if (l > 0)
                backtrace(res, tmp + "(", l - 1, r);
            if (r > 0)
                backtrace(res, tmp + ")", l, r - 1);
        }
    }
}
// @lc code=end
