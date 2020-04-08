/*
 * @lc app=leetcode id=7 lang=java
 *
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (25.50%)
 * Likes:    3031
 * Dislikes: 4778
 * Total Accepted:    1M
 * Total Submissions: 3.9M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 * 
 * Example 1:
 * 
 * 
 * Input: 123
 * Output: 321
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -123
 * Output: -321
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 120
 * Output: 21
 * 
 * 
 * Note:
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
 * of this problem, assume that your function returns 0 when the reversed
 * integer overflows.
 * 
 */

// @lc code=start
class Solution {
    public int reverse(int x) {
        int res = 0;
        int dig;
        while (x != 0) {
            dig = x % 10;
            if (res > 214748364 || (res == 214748364 && dig > 7))
                return 0;
            if (res < -214748364 || (res == -214748364 && dig < -8))
                return 0;
            res = res * 10 + dig;
            x /= 10;
        }
        return res;
    }
}
// @lc code=end
