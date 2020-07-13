/*
 * @lc app=leetcode.cn id=307 lang=cpp
 *
 * [307] 区域和检索 - 数组可修改
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class NumArray {
    size_t n;
    vector<int> tree;

public:
    NumArray(vector<int>& nums) : n(nums.size()), tree(2 * n)
    {
        for (size_t i = n, j = 0; j < n; ++j) tree[i++] = nums[j];
        for (int i = n - 1; i > 0; --i) tree[i] = tree[2 * i] + tree[2 * i + 1];
    }

    void update(int i, int val)
    {
        i += n;
        val -= tree[i];
        while (i)
        {
            tree[i] += val;
            i >>= 1;
        }
    }

    int sumRange(int i, int j)
    {
        int res = 0;
        for (i += n, j += n; i <= j; i /= 2, j /= 2)
        {
            if (i % 2) res += tree[i++];       // i是右孩子
            if (j % 2 == 0) res += tree[j--];  // j是左孩子
        }
        return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
// @lc code=end
