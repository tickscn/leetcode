/*
 * @lc app=leetcode id=6 lang=java
 *
 * [6] ZigZag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (33.34%)
 * Likes:    1479
 * Dislikes: 4240
 * Total Accepted:    426.4K
 * Total Submissions: 1.2M
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 * 
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * 
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 * 
 * 
 * string convert(string s, int numRows);
 * 
 * Example 1:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 * 
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 * 
 */

// @lc code=start
class Solution {
    public String convert(String s, int numRows) {
        if (s.length() == 0 || numRows == 1 || numRows == 0)
            return s;
        StringBuffer buf = new StringBuffer();
        int zSize = 2 * numRows - 2;
        for (int i = 0; i < numRows; i++) {
            for (int j = i; j < s.length(); j = j + zSize) {
                buf.append(s.charAt(j));
                if (i != 0 && i != numRows - 1 && j - 2 * i + zSize < s.length())
                    buf.append(s.charAt(zSize - 2 * i + j));
            }
        }
        return buf.toString();
    }
}
// @lc code=end
