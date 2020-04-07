/*
 * @lc app=leetcode id=3 lang=java
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (28.88%)
 * Likes:    8249
 * Dislikes: 500
 * Total Accepted:    1.4M
 * Total Submissions: 4.7M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
import java.util.HashMap;

class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashMap<Character, Integer> table = new HashMap<>();
        int res = 0;
        int l = 0;
        for (int i = 0; i < s.length(); i++) {
            if (table.containsKey(s.charAt(i)) && l < table.get(s.charAt(i)) + 1) {
                l = table.get(s.charAt(i)) + 1;
            }
            table.put(s.charAt(i), i);
            if (res < i - l + 1)
                res = i - l + 1;
        }
        return res;
    }
}
// @lc code=end
