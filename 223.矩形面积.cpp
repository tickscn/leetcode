/*
 * @lc app=leetcode.cn id=223 lang=cpp
 *
 * [223] 矩形面积
 */

// @lc code=start
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
    {
        long long res = (long long)(C - A) * (D - B) + (G - E) * (H - F);
        if (C <= E || G <= A || H <= B || D <= F) return res;
        int W, T;
        if (G < C)
        {
            if (E < A)
                W = G - A;
            else
                W = G - E;
        }
        else
        {
            if (E < A)
                W = C - A;
            else
                W = C - E;
        }
        if (H < D)
        {
            if (F < B)
                T = H - B;
            else
                T = H - F;
        }
        else
        {
            if (F < B)
                T = D - B;
            else
                T = D - F;
        }
        return res - T * W;
    }
};
// @lc code=end
