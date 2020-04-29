import java.util.*;

/*
 * @lc app=leetcode.cn id=17 lang=java
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (53.25%)
 * Likes:    684
 * Dislikes: 0
 * Total Accepted:    106.1K
 * Total Submissions: 199.2K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入："23"
 * 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * 说明:
 * 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
 * 
 */

// @lc code=start
class Solution {
    public List<String> letterCombinations(String digits) {
        List<String> res = new ArrayList<>();
        if (digits.length() == 0)
            return res;
        String[] map = new String[] { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        int[] index = new int[digits.length()];
        int j, carry;
        do {
            j = index.length - 1;
            carry = 1;
            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < digits.length(); i++) {
                int k = digits.charAt(i) - '2';
                builder.append(map[k].charAt(index[i]));
            }
            res.add(builder.toString());

            while (j >= 0) {
                int k = map[digits.charAt(j) - '2'].length();
                int tmp = index[j];
                index[j] = (tmp + carry) % k;
                carry = (tmp + carry) / k;
                if (carry == 0)
                    break;
                j--;
            }
        } while (j >= 0);
        return res;
    }
}
// @lc code=end
