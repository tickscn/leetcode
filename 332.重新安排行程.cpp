/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets)
    {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> from_to;
        vector<string> res;
        for (auto& ticket : tickets) from_to[ticket[0]].push(ticket[1]);
        dfs("JFK", from_to, res);
        return vector<string>(res.rbegin(), res.rend());
    }
    void dfs(string from, unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& from_to, vector<string>& res)
    {
        while (!from_to[from].empty())
        {
            string next = from_to[from].top();
            from_to[from].pop();
            dfs(next, from_to, res);
        }
        res.push_back(from);
    }
};
// @lc code=end
