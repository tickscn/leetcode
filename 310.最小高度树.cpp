/*
 * @lc app=leetcode.cn id=310 lang=cpp
 *
 * [310] 最小高度树
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges)
    {
        if (n == 1) return {0};
        vector<unordered_set<int>> adjs(n);
        queue<int> Q;
        for (vector<int>& edge : edges)
        {
            adjs[edge[0]].insert(edge[1]);
            adjs[edge[1]].insert(edge[0]);
        }
        for (int i = 0; i < n; ++i)
            if (adjs[i].size() == 1) Q.push(i);
        while (n > 2)
        {
            int i = Q.size();
            n -= i;
            for (; i > 0; --i)
            {
                int v = Q.front();
                Q.pop();
                for (int n : adjs[v])
                {
                    adjs[n].erase(v);
                    if (adjs[n].size() == 1) Q.push(n);
                }
            }
        }
        vector<int> res;
        while (!Q.empty())
        {
            res.push_back(Q.front());
            Q.pop();
        }
        return res;
    }
};
// @lc code=end
