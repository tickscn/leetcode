/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
	bool isValidBST(TreeNode* root, long& pre)
	{
		if (!root) return true;
		if (!isValidBST(root->left, pre)) return false;
		if (root->val <= pre) return false;
		pre = root->val;
		return isValidBST(root->right, pre);
	}
	bool isValidBST(TreeNode* root)
	{
		long pre = LONG_MIN;
		return isValidBST(root, pre);
	}
};
