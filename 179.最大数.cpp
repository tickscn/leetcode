/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 *
 * https://leetcode-cn.com/problems/largest-number/description/
 *
 * algorithms
 * Medium (36.20%)
 * Likes:    299
 * Dislikes: 0
 * Total Accepted:    31.5K
 * Total Submissions: 86.9K
 * Testcase Example:  '[10,2]'
 *
 * 给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。
 *
 * 示例 1:
 *
 * 输入: [10,2]
 * 输出: 210
 *
 * 示例 2:
 *
 * 输入: [3,30,34,5,9]
 * 输出: 9534330
 *
 * 说明: 输出结果可能非常大，所以你需要返回一个字符串而不是整数。
 *
 */

// @lc code=start
class Solution {
public:
    string largestNumber(vector<int>& nums)
    {
        vector<string> vecstr(nums.size());
        bool flag = false;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i]) flag = true;
            vecstr[i] = to_string(nums[i]);
        }
        sort(vecstr.begin(), vecstr.end(), [](const string& v1, const string& v2) { return v1 + v2 > v2 + v1; });
        return flag ? accumulate(vecstr.begin(), vecstr.end(), string("")) : "0";
    }
};
// @lc code=end
