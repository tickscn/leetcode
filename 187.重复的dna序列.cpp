/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 *
 * https://leetcode-cn.com/problems/repeated-dna-sequences/description/
 *
 * algorithms
 * Medium (44.46%)
 * Likes:    93
 * Dislikes: 0
 * Total Accepted:    17.5K
 * Total Submissions: 39.2K
 * Testcase Example:  '"AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"'
 *
 * 所有 DNA 都由一系列缩写为 A，C，G 和 T 的核苷酸组成，例如：“ACGAATTCCG”。在研究 DNA 时，识别 DNA
 * 中的重复序列有时会对研究非常有帮助。
 *
 * 编写一个函数来查找目标子串，目标子串的长度为 10，且在 DNA 字符串 s 中出现次数超过一次。
 *
 *
 *
 * 示例：
 *
 * 输入：s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
 * 输出：["AAAAACCCCC", "CCCCCAAAAA"]
 *
 */

// @lc code=start
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        if (s.length() < 10) return {};
        vector<string> res;
        unordered_map<string, int> table;
        for (int i = 0; i < s.length() - 9; ++i)
        {
            if (table[s.substr(i, 10)] == 1) res.emplace_back(s.substr(i, 10));
            ++table[s.substr(i, 10)];
        }
        return res;
    }
};
// @lc code=end
