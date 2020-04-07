/*
 * @lc app=leetcode id=5 lang=java
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (27.96%)
 * Likes:    5889
 * Dislikes: 486
 * Total Accepted:    846.8K
 * Total Submissions: 2.9M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */

// @lc code=start
class Solution {
    public String longestPalindrome(String s) {
        if (s == null || s.length() == 0)
            return "";
        if (s.length() == 1)
            return s;
        boolean[][] dp = new boolean[s.length()][];
        for (int i = 0; i < dp.length; i++) {
            dp[i] = new boolean[s.length() - i + 1];
            dp[i][0] = true;
            dp[i][1] = true;
        }
        int maxlength = 1;
        int maxBegin = 0;
        for (int len = 2; len <= s.length(); len++)
            for (int i = 0; i <= s.length() - len; i++) {
                if (s.charAt(i) == s.charAt(i + len - 1) && dp[i + 1][len - 2]) {
                    maxlength = len;
                    maxBegin = i;
                    dp[i][len] = true;
                } else
                    dp[i][len] = false;
            }
        return s.substring(maxBegin, maxBegin + maxlength);
    }
}
// @lc code=end
