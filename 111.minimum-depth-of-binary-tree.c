/*
 * @lc app=leetcode id=111 lang=c
 *
 * [111] Minimum Depth of Binary Tree
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int minDepth(struct TreeNode* root)
{
	if (!root)
		return 0;
	if (!root->left && !root->right)
		return 1;
	int a = INT_MAX / 2, b = INT_MAX / 2;
	if (root->left)
		a = minDepth(root->left) + 1;
	if (root->right)
		b = minDepth(root->right) + 1;
	return a < b ? a : b;
}
