/*
 * @lc app=leetcode id=112 lang=c
 *
 * [112] Path Sum
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool hasPathSum(struct TreeNode* root, int sum)
{
	if (!root)
		return false;
	if (!root->left && !root->right && root->val == sum)
		return true;
	return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}
