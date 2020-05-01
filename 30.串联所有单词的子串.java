/*
 * @lc app=leetcode.cn id=30 lang=java
 *
 * [30] 串联所有单词的子串
 *
 * https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/description/
 *
 * algorithms
 * Hard (30.29%)
 * Likes:    256
 * Dislikes: 0
 * Total Accepted:    31K
 * Total Submissions: 102.1K
 * Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
 *
 * 给定一个字符串 s 和一些长度相同的单词 words。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。
 * 
 * 注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：
 * ⁠ s = "barfoothefoobarman",
 * ⁠ words = ["foo","bar"]
 * 输出：[0,9]
 * 解释：
 * 从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
 * 输出的顺序不重要, [9,0] 也是有效答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入：
 * ⁠ s = "wordgoodgoodgoodbestword",
 * ⁠ words = ["word","good","best","word"]
 * 输出：[]
 * 
 * 
 */

// @lc code=start

class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> res = new ArrayList<>();
        if (words.length == 0 || s.length() == 0)
            return res;
        if (words.length * words[0].length() > s.length())
            return res;
        Map<String, Integer> wordsCount = new HashMap<>();
        for (int i = 0; i < words.length; i++) {
            wordsCount.put(words[i], wordsCount.getOrDefault(words[i], 0) + 1);
        }
        int wordLen = words[0].length();
        int substringLen = words.length * wordLen;
        for (int i = 0; i < wordLen; i++) {
            int left = i;
            int right = i;
            Map<String, Integer> windowCount = new HashMap<>();
            while (right + wordLen <= s.length()) {
                String temp = s.substring(right, right + wordLen);
                right += wordLen;
                if (!wordsCount.containsKey(temp)) {
                    left = right;
                    windowCount.clear();
                } else {
                    windowCount.put(temp, windowCount.getOrDefault(temp, 0) + 1);
                    while (windowCount.get(temp) > wordsCount.get(temp)) {
                        String removeTemp = s.substring(left, left + wordLen);
                        windowCount.put(removeTemp, windowCount.get(removeTemp) - 1);
                        left += wordLen;
                    }
                    if (right - left == substringLen)
                        res.add(left);
                }
            }
        }
        return res;
    }
}
// @lc code=end
