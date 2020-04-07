/*
 * @lc app=leetcode id=687 lang=cpp
 *
 * [687] Longest Univalue Path
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int longestUnivaluePath(TreeNode* root)
    {
        int ret = 0;
        recursion(root, ret);

        return ret;
    }
    int recursion(TreeNode* node, int& res)
    {
        if (!node) return 0;
        int left  = recursion(node->left, res);
        int right = recursion(node->right, res);
        left      = (node->left && node->left->val == node->val) ? left + 1 : 0;
        right     = (node->right && node->right->val == node->val) ? right + 1 : 0;
        res       = max(res, left + right);
        return max(left, right);
    }
};
// @lc code=end
