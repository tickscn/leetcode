/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
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
	int sumOfLeftLeaves(TreeNode* root, bool isLeft = false)
	{
		if (!root) return 0;
		if (!root->left && !root->right && isLeft) return root->val;
		return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
	}
};
