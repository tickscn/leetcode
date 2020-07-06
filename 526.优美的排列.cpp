/*
 * @lc app=leetcode.cn id=526 lang=cpp
 *
 * [526] 优美的排列
 */

// @lc code=start
class Solution {

public:
    int countArrangement(int N)
    {
        return dfs(1, N, -1);
    }
    int dfs(int i, int N, int unused)
    {
        if (i > N) return 1;
        int res = 0;
        for (int j = 1; j <= N; ++j)
            if (((1 << j) & unused) && (i % j == 0 || j % i == 0))
            {
                res += dfs(i + 1, N, unused & ~(1 << j));
            }
        return res;
    }
};
// @lc code=end
