/*
 * @lc app=leetcode id=104 lang=c
 *
 * [104] Maximum Depth of Binary Tree
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
