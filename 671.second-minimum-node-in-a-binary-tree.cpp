/*
 * @lc app=leetcode id=671 lang=cpp
 *
 * [671] Second Minimum Node In a Binary Tree
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
    int findSecondMinimumValue(TreeNode* root)
    {
        if (!root->left) return -1;
        int left  = (root->left->val == root->val) ? findSecondMinimumValue(root->left) : root->left->val;
        int right = (root->right->val == root->val) ? findSecondMinimumValue(root->right) : root->right->val;
        return (left == -1 || right == -1) ? max(left, right) : min(left, right);
    }
};
// @lc code=end
