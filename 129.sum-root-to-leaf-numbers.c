/*
 * @lc app=leetcode id=129 lang=c
 *
 * [129] Sum Root to Leaf Numbers
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int sumNumbersDFS(struct TreeNode* root, int sum)
{
	if (!root) return 0;
	sum = sum * 10 + root->val;
	if (!root->left && !root->right) return sum;
	return sumNumbersDFS(root->left, sum) + sumNumbersDFS(root->right, sum);
}
int sumNumbers(struct TreeNode* root)
{
	return sumNumbersDFS(root, 0);
}
