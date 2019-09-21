/*
 * @lc app=leetcode id=124 lang=c
 *
 * [124] Binary Tree Maximum Path Sum
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int maxPathSumR(struct TreeNode* root, int* res)
{
	if (!root) return 0;
	int left  = maxPathSumR(root->left, res);
	left      = left > 0 ? left : 0;
	int right = maxPathSumR(root->right, res);
	right     = right > 0 ? right : 0;
	if (left + right + root->val > *res) *res = left + right + root->val;
	return root->val + (left > right ? left : right);
}
int maxPathSum(struct TreeNode* root)
{
	int res = INT_MIN;
	maxPathSumR(root, &res);
	return res;
}
