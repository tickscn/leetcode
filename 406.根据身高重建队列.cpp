/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 *
 * https://leetcode-cn.com/problems/queue-reconstruction-by-height/description/
 *
 * algorithms
 * Medium (64.74%)
 * Likes:    351
 * Dislikes: 0
 * Total Accepted:    30.7K
 * Total Submissions: 47.4K
 * Testcase Example:  '[[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]'
 *
 * 假设有打乱顺序的一群人站成一个队列。 每个人由一个整数对(h,
 * k)表示，其中h是这个人的身高，k是排在这个人前面且身高大于或等于h的人数。 编写一个算法来重建这个队列。
 *
 * 注意：
 * 总人数少于1100人。
 *
 * 示例
 *
 *
 * 输入:
 * [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
 *
 * 输出:
 * [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
 *
 *
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
    {
        sort(people.begin(), people.end(), [](const vector<int>& v1, const vector<int>& v2) {
            return v1[0] == v2[0] ? v1[1] < v2[1] : v1[0] > v2[0];
        });
        vector<vector<int>> res;
        for (int i = 0; i < people.size(); ++i) { res.insert(res.begin() + people[i][1], std::move(people[i])); }
        return res;
    }
};
// @lc code=end
