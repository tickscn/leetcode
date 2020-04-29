/*
 * @lc app=leetcode.cn id=20 lang=java
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (41.45%)
 * Likes:    1546
 * Dislikes: 0
 * Total Accepted:    264.8K
 * Total Submissions: 638.8K
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 
 * 
 * 注意空字符串可被认为是有效字符串。
 * 
 * 示例 1:
 * 
 * 输入: "()"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "()[]{}"
 * 输出: true
 * 
 * 
 * 示例 3:
 * 
 * 输入: "(]"
 * 输出: false
 * 
 * 
 * 示例 4:
 * 
 * 输入: "([)]"
 * 输出: false
 * 
 * 
 * 示例 5:
 * 
 * 输入: "{[]}"
 * 输出: true
 * 
 */

// @lc code=start

import java.util.*;

class Solution {
    public boolean isValid(String s) {
        if (s.length() % 2 == 1)
            return false;
        Stack<Character> st = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            switch (s.charAt(i)) {
                case '(':
                case '[':
                case '{':
                    st.push(s.charAt(i));
                    break;
                case ')':
                    if (st.empty() || st.pop() != '(')
                        return false;
                    break;
                case ']':
                    if (st.empty() || st.pop() != '[')
                        return false;
                    break;
                case '}':
                    if (st.empty() || st.pop() != '{')
                        return false;
                    break;
            }
        }
        return st.empty();
    }
}
// @lc code=end
