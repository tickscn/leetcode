/*
 * @lc app=leetcode id=110 lang=c
 *
 * [110] Balanced Binary Tree
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root)
{
	if (root)
	{
		int a = maxDepth(root->left) + 1;
		int b = maxDepth(root->right) + 1;
		return a > b ? a : b;
	}
	return 0;
}
bool isBalanced(struct TreeNode* root)
{
	if (root)
	{
		if (abs(maxDepth(root->left) - maxDepth(root->right)) > 1)
			return false;
		if (!isBalanced(root->left))
			return false;
		if (!isBalanced(root->right))
			return false;
	}
	return true;
}
