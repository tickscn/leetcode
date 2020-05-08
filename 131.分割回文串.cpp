/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 *
 * https://leetcode-cn.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (67.06%)
 * Likes:    276
 * Dislikes: 0
 * Total Accepted:    30.6K
 * Total Submissions: 45.6K
 * Testcase Example:  '"aab"'
 *
 * 给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
 *
 * 返回 s 所有可能的分割方案。
 *
 * 示例:
 *
 * 输入: "aab"
 * 输出:
 * [
 * ⁠ ["aa","b"],
 * ⁠ ["a","a","b"]
 * ]
 *
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool isPartition(const string& s)
    {
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            if (s[i] != s[j]) return false;
            ++i;
            --j;
        }
        return true;
    }
    vector<vector<string>> partition(string s)
    {
        if (s.empty()) return {};
        vector<vector<string>> res;
        vector<string> temp;
        recursion(res, temp, s, 0, s.length() - 1);
        return res;
    }

    void recursion(vector<vector<string>>& res, vector<string>& temp, string& s, int b, int e)
    {
        if (b > e) { res.push_back(temp); }
        else
        {
            for (int i = 1; i <= e - b + 1; ++i)
            {
                if (isPartition(s.substr(b, i)))
                {
                    temp.push_back(s.substr(b, i));
                    recursion(res, temp, s, b + i, e);
                    temp.pop_back();
                }
            }
        }
    }
};
// @lc code=end
