/*
 * @lc app=leetcode.cn id=897 lang=cpp
 *
 * [897] 递增顺序查找树
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
    TreeNode* increasingBST(TreeNode* root)
    {
        return inOrder(root).first;
    }
    pair<TreeNode*, TreeNode*> inOrder(TreeNode* root)
    {
        if (!root) return {nullptr, nullptr};
        pair<TreeNode*, TreeNode*> res(root, root);
        if (root->left)
        {
            auto tmp          = inOrder(root->left);
            root->left        = nullptr;
            res.first         = tmp.first;
            tmp.second->right = root;
        }
        if (root->right)
        {
            auto tmp    = inOrder(root->right);
            root->right = tmp.first;
            res.second  = tmp.second;
        }
        return res;
    }
};
// @lc code=end
