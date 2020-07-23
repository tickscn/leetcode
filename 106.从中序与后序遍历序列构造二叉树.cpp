/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        return buildTree(inorder, 0, postorder, 0, postorder.size() - 1);
    }
    TreeNode* buildTree(vector<int>& inorder, int inBeg, vector<int>& postorder, int pBeg, int pEnd)
    {
        if (pEnd < pBeg) return nullptr;
        TreeNode* root = new TreeNode(postorder[pEnd]);
        int leftEnd    = 0;
        while (inorder[leftEnd + inBeg] != postorder[pEnd]) ++leftEnd;
        root->left  = buildTree(inorder, inBeg, postorder, pBeg, pBeg + leftEnd - 1);
        root->right = buildTree(inorder, inBeg + leftEnd + 1, postorder, pBeg + leftEnd, pEnd - 1);
        return root;
    }
};
// @lc code=end
