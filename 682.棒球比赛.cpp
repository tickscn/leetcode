/*
 * @lc app=leetcode.cn id=682 lang=cpp
 *
 * [682] 棒球比赛
 */

// @lc code=start
class Solution {
public:
    int calPoints(vector<string>& ops)
    {
        int res = 0;
        vector<int> pre;
        for (auto& op : ops)
        {
            if (op == "C")
            {
                res -= pre.back();
                pre.pop_back();
            }
            else if (op == "D")
            {
                int p = pre.back() * 2;
                res += p;
                pre.push_back(p);
            }
            else if (op == "+")
            {
                int p = pre.back() + pre[pre.size() - 2];
                res += p;
                pre.push_back(p);
            }
            else
            {
                int p = stoi(op);
                res += p;
                pre.push_back(p);
            }
        }
        return res;
    }
};
// @lc code=end
