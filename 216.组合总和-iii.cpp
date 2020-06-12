/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 *
 * https://leetcode-cn.com/problems/combination-sum-iii/description/
 *
 * algorithms
 * Medium (71.13%)
 * Likes:    120
 * Dislikes: 0
 * Total Accepted:    22.1K
 * Total Submissions: 31K
 * Testcase Example:  '3\n7'
 *
 * 找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
 *
 * 说明：
 *
 *
 * 所有数字都是正整数。
 * 解集不能包含重复的组合。 
 *
 *
 * 示例 1:
 *
 * 输入: k = 3, n = 7
 * 输出: [[1,2,4]]
 *
 *
 * 示例 2:
 *
 * 输入: k = 3, n = 9
 * 输出: [[1,2,6], [1,3,5], [2,3,4]]
 *
 *
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        if (k == 0 || k > 9 || n == 0 || n > 45) return {};
        vector<vector<int>> res;
        vector<int> temp;
        dfs(res, temp, n, k, 1);
        return res;
    }
    void dfs(vector<vector<int>>& res, vector<int>& temp, int n, int k, int start)
    {
        if (n < 0 || temp.size() > k) return;
        if (temp.size() == k && n == 0)
        {
            res.emplace_back(temp);
            return;
        }
        for (int i = start; i < 10 && n - i >= 0; ++i)
        {
            temp.push_back(i);
            dfs(res, temp, n - i, k, i + 1);
            temp.pop_back();
        }
    }
};
// @lc code=end
